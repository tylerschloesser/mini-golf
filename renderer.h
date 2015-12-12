#ifndef RENDERER_H
#include "physics.h"
#define RENDERER_H

#include "course.h"
#include "ball.h"
#include "window.h"

class Renderer {
private:
    Course& course;
    Ball& ball;
    Window& window;

    SDL_Renderer* sdl_renderer;

    int scale_x, scale_y;
    glm::ivec2 scale;

    void set_color(uint8_t r, uint8_t g, uint8_t b);
public:
    Renderer(Course& course, Ball& ball, Window& window);
    int init();
    void render();
};

#endif // RENDERER_H
