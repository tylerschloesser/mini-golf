#include <cstdio>

#include <SDL2/SDL.h>

#include "game.h"

#define TARGET_FPS 60
#define FPS_UPDATE_FREQ 2000 // ms
#define FRAMES_DEN (FPS_UPDATE_FREQ / 1000.0)

Game::Game(Renderer& renderer, Physics& physics) :
    last_frame(0), renderer(renderer), physics(physics) {

    frame_time = 1000 / TARGET_FPS;

    shot_line = new Line();
    shot_line->visible = false;
    renderer.add(shot_line);

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
                {
                    handle_mouse_click(sdl_event.button);
                    break;
                }
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

        physics.update(elapsed);
        renderer.render();
    }
}

void Game::update(uint32_t elapsed) {
}

void Game::handle_mouse_click(SDL_MouseButtonEvent event) {
    if (event.state == SDL_PRESSED) {
        shot_line->visible = true;
        shot_line->a = glm::vec2(event.x, event.y);
        shot_line->b = glm::vec2(event.x + 100, event.y + 100);
        shot_line->color = Color::BLACK;
    } else { // SDL_RELEASED
        shot_line->visible = false;
    }
}
