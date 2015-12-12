#include <cstdio>

#include "renderer.h"

Renderer::Renderer(Course& course, Window& window) :
    course(course), window(window), sdl_renderer(NULL) {}

int Renderer::init() {
    sdl_renderer = SDL_CreateRenderer(window.sdl_window, -1, 0);
    if (sdl_renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

void Renderer::render() {

    set_color(0xff, 0xff, 0xcc);
    SDL_RenderClear(sdl_renderer);

    set_color(0xff, 0, 0);
    SDL_RenderDrawLine(sdl_renderer, 0,0,window.width, window.height);

    SDL_RenderPresent(sdl_renderer);
}

void Renderer::set_color(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, 0xFF);  
}
