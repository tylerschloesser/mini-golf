#include <cstdio>

#include <SDL2/SDL.h>

#include "game.h"

#define TARGET_FPS 60
#define FPS_UPDATE_FREQ 2000 // ms
#define FRAMES_DEN (FPS_UPDATE_FREQ / 1000.0)

Game::Game(Renderer& renderer, Physics& physics) :
    last_frame(0), renderer(renderer), physics(physics) {

    frame_time = 1000 / TARGET_FPS;

    fprintf(stderr, "Game initialized\n  frame_time: %i ms\n", frame_time);
}

void Game::run() {

    bool stop = false;
    SDL_Event sdl_event;
    while(!stop) {
        while(SDL_PollEvent(&sdl_event) != 0) {
            if(sdl_event.type == SDL_QUIT) {
                stop = true;
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
