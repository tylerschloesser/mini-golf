#include <cstdio>
#include <cmath>

#include <SDL2/SDL2_gfxPrimitives.h>

#include "renderer.h"

Renderer::Renderer(Course& course, Ball& ball, Window& window) :
    course(course), ball(ball), window(window), sdl_renderer(NULL) {

    float scale_x = static_cast<float>(window.width) / course.width;
    float scale_y = static_cast<float>(window.height) / course.height;
    scale = glm::vec2(scale_x, scale_y);

    fprintf(stderr, "Renderer created\n  scale: (%.1f, %.1f)\n",
        scale[0], scale[1]);
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

    // render course
    for (std::vector<glm::vec2>::size_type i = 0; i < vertices.size(); i++) {
        int ia = i, ib = (i + 1) % vertices.size();
        glm::vec2 a = vertices[ia] * scale, b = vertices[ib] * scale;
        SDL_RenderDrawLine(sdl_renderer, a[0], a[1], b[0], b[1]);
    }

    // render hole
    {
        glm::vec2 position = course.hole * scale;
        // TODO scale in both directions
        float radius = course.hole_radius * scale[0];
        int x = position[0], y = position[1];
        assert(filledCircleColor(sdl_renderer, x, y, radius, Color::GRAY.hex) == 0);
    }

    // render ball
    {
        glm::vec2 position = ball.position * scale;
        // TODO scale in both directions
        float radius = ball.radius * scale[0];
        int x = position[0], y = position[1];
        assert(filledCircleColor(sdl_renderer, x, y, radius, 0xFFFF00FF) == 0);
    }

    for (Line* line : lines) {
        if (line->visible) {
            glm::vec2 a = line->a + line->translate, b = line->b + line->translate;
            SDL_RenderDrawLine(sdl_renderer, a[0], a[1], b[0], b[1]);
        }
    }

    SDL_RenderPresent(sdl_renderer);
}

void Renderer::set_color(uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(sdl_renderer, r, g, b, 0xFF);
}

void Renderer::set_color(const Color& color) {
    set_color(color.r, color.g, color.b);
}

void Renderer::add(Line* line) {
    lines.push_back(line);
}

