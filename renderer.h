#ifndef RENDERER_H
#include "physics.h"
#define RENDERER_H

#include "course.h"
#include "ball.h"
#include "window.h"
#include "line.h"
#include "color.h"

class Renderer {
private:
    Course& course;
    Ball& ball;
    Window& window;

    SDL_Renderer* sdl_renderer;
    std::vector<Line*> lines;

    void set_color(uint8_t r, uint8_t g, uint8_t b);
    void set_color(const Color& color);
public:
    Renderer(Course& course, Ball& ball, Window& window);
    int init();
    void render();

    void add(Line* line);

    glm::vec2 scale;
};

#endif // RENDERER_H
