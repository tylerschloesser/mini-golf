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
    shot_line->visible = false;
    shot_line->color = Color::BLACK;
    renderer.add(shot_line);

    state = DROP_BALL;

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
    float x1 = ball.position[0], y1 = ball.position[1];
    float x2 = course.hole[0], y2 = course.hole[1];
    float dx = x2 - x1, dy = y2 - y1;
    float d = sqrt(dx * dx + dy * dy);

    if (d < course.hole_radius) {
        fprintf(stderr, "you win!\n");
        state = DROP_BALL;

        int x, y;
        SDL_GetMouseState(&x, &y);
        ball.velocity = ball.acceleration = glm::vec2(0, 0);
        ball.position = glm::vec2(x, y) / renderer.scale;
    }
}

void Game::handle_mouse_click(SDL_MouseButtonEvent event) {
    if (event.state == SDL_PRESSED) {
        if (state == PLAY) {
            shot_line->visible = true;
            shot_line->a = shot_line->b = glm::vec2(event.x, event.y);
        }
    } else { // SDL_RELEASED
        if (state == PLAY) {
            shot_line->visible = false;
            glm::vec2 velocity = shot_line->b - shot_line->a;
            ball.velocity = velocity / renderer.scale;

            float friction = .99f;
            ball.acceleration = glm::normalize(-velocity) * friction;
        } else { // DROP_BALL
            state = PLAY;
        }
    }
}

void Game::handle_mouse_motion(SDL_MouseMotionEvent event) {
    assert(!shot_line->visible || (event.state | SDL_BUTTON_LMASK));

    if (state == DROP_BALL) {
        ball.position = glm::vec2(event.x, event.y) / renderer.scale;
    } else if (shot_line->visible) {
        glm::vec2 &a = shot_line->a;
        glm::vec2 b(event.x, event.y);
        shot_line->b = a + -(b - a);
    }
}
