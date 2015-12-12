#include <cstdio>

#include "renderer.h"

Renderer::Renderer(Course& course, Window& window) :
    course(course), window(window), sdl_renderer(NULL) {

    scale_x = window.width / static_cast<double>(course.width);
    scale_y = window.height / static_cast<double>(course.height);

    fprintf(stderr, "Renderer created\n  scale_x: %.2f\n  scale_y: %.2f\n",
        scale_x, scale_y);
}

int Renderer::init() {
    sdl_renderer = SDL_CreateRenderer(window.sdl_window, -1, 0);
    if (sdl_renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer: %s\n", SDL_GetError());
        return 1;
    }
    fprintf(stderr, "Renderer initialized\n");
    return 0;
}

void Renderer::render() {

    set_color(0xff, 0xff, 0xcc);
    SDL_RenderClear(sdl_renderer);

    for (glm::ivec2 vertex : course.vertices) {

    }

    set_color(0xff, 0, 0);
    SDL_RenderDrawLine(sdl_renderer, 0,0,window.width, window.height);

    SDL_RenderPresent(sdl_renderer);
}

void Renderer::set_color(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, 0xFF);  
}
