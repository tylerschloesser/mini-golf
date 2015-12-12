#include <cstdio>

#include <SDL2/SDL.h>

#include "game.h"

Game::Game(Course& course) : last_frame(0), course(course) {
    fprintf(stderr, "Game initialized\n");
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
    }
}
