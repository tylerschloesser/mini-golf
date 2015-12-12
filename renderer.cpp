#include <cstdio>
#include <cmath>

#include <SDL2/SDL2_gfxPrimitives.h>

#include "renderer.h"

Renderer::Renderer(Course& course, Ball& ball, Window& window) :
    course(course), ball(ball), window(window), sdl_renderer(NULL) {

    scale_x = window.width / course.width;
    scale_y = window.height / course.height;
    scale = glm::vec2(scale_x, scale_y);

    fprintf(stderr, "Renderer created\n  scale_x: %i\n  scale_y: %i\n",
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

    std::vector<glm::vec2> vertices = course.vertices;
    assert(vertices.size() > 1);
    set_color(0xff, 0, 0);

    for (std::vector<glm::vec2>::size_type i = 0; i < vertices.size(); i++) {
        int ia = i, ib = (i + 1) % vertices.size();
        glm::vec2 a = vertices[ia] * scale, b = vertices[ib] * scale;
        SDL_RenderDrawLine(sdl_renderer, a[0], a[1], b[0], b[1]);
    }

    {
        glm::vec2 position = ball.position * scale;
        int x = position[0], y = position[1];
        assert(filledCircleColor(sdl_renderer, x, y, 10, 0xFFFF00FF) == 0);
    }

    SDL_RenderPresent(sdl_renderer);
}

void Renderer::set_color(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, 0xFF);
}
