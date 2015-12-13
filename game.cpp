#include <cstdio>

#include <SDL2/SDL.h>
#include <glm/geometric.hpp>

#include "game.h"

#define TARGET_FPS 60
#define FPS_UPDATE_FREQ 2000 // ms
#define FRAMES_DEN (FPS_UPDATE_FREQ / 1000.0)

Game::Game(Renderer& renderer, Physics& physics, Course& course, Ball& ball) :
    renderer(renderer), physics(physics), course(course), ball(ball), last_frame(0) {

    frame_time = 1000 / TARGET_FPS;

    shot_line = new Line();
    shot_line->color = Color::BLACK;
    renderer.add(shot_line);

    set_state(DROP_BALL);

    fprintf(stderr, "Game initialized\n  frame_time: %i ms\n", frame_time);
}

void Game::run() {

    bool stop = false;
    SDL_Event sdl_event;
    while(!stop) {
        while(SDL_PollEvent(&sdl_event) != 0) {
            switch(sdl_event.type) {
                case SDL_QUIT:
                    stop = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEBUTTONDOWN:
                    handle_mouse_click(sdl_event.button);
                    break;
                case SDL_MOUSEMOTION:
                    handle_mouse_motion(sdl_event.motion);
                    break;
                default:
                    break;
            }
        }

        uint32_t elapsed = 0;
        uint32_t now = SDL_GetTicks();
        if (last_frame != 0) {
            elapsed = now - last_frame;
            if (elapsed < frame_time) {
                SDL_Delay(frame_time - elapsed);
            }
        }
        last_frame = now;

        // calculate fps
        {
            static uint32_t last_fps_update = 0;
            static uint32_t frames = 0;
            frames++;
            if (last_fps_update == 0) {
                last_fps_update = last_frame;
            } else {
                uint32_t elapsed = last_frame - last_fps_update;
                if (elapsed > FPS_UPDATE_FREQ) {
                    double fps = frames / FRAMES_DEN;
                    fprintf(stderr, "fps: %.2f\n", fps);
                    frames = 0;
                    last_fps_update = last_frame;
                }
            }
        }

        update(elapsed);
        physics.update(elapsed);
        renderer.render();
    }
}

void Game::update(uint32_t elapsed) {
    if (state == DROP_BALL) {
        return;
    }

    float x1 = ball.position[0], y1 = ball.position[1];
    float x2 = course.hole[0], y2 = course.hole[1];
    float dx = x2 - x1, dy = y2 - y1;
    float d = sqrt(dx * dx + dy * dy);

    if (d < course.hole_radius) {
        printf("you win!\n");
        set_state(DROP_BALL);

        int x, y;
        SDL_GetMouseState(&x, &y);
        ball.stop();
        ball.position = glm::vec2(x, y) / renderer.scale;
    }
}

void Game::handle_mouse_click(SDL_MouseButtonEvent event) {
    if (event.state == SDL_PRESSED) {
        if (event.button == SDL_BUTTON_RIGHT) {
            set_state(DROP_BALL);
            ball.stop();
        } else if(state == DROP_BALL && event.button == SDL_BUTTON_LEFT) {
            set_state(PLAY);
        }
    } else { // SDL_RELEASED
        if (state == PREPARE_SHOT) {
            set_state(PLAY);

            glm::vec2 velocity = shot_line->b - shot_line->a;
            ball.velocity = velocity / renderer.scale;

            float friction = .99f;
            ball.acceleration = glm::normalize(-velocity) * friction;
        }
    }
}

void Game::handle_mouse_motion(SDL_MouseMotionEvent event) {
    if (state == DROP_BALL) {
        ball.position = glm::vec2(event.x, event.y) / renderer.scale;
    } else if (event.state & SDL_BUTTON_LMASK) {
        if (state == PLAY) {
            set_state(PREPARE_SHOT);

            shot_line->a = shot_line->b = glm::vec2(event.x, event.y);
            shot_line->translate =  ball.position * renderer.scale - glm::vec2(event.x, event.y);
        } else if (state == PREPARE_SHOT) {
            glm::vec2 &a = shot_line->a;
            glm::vec2 b(event.x, event.y);
            shot_line->b = a + -(b - a);
        }
    }
}

void Game::set_state(GameState state) {
    this->state = state;
    shot_line -> visible = state == PREPARE_SHOT;
}
