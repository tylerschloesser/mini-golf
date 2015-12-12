#ifndef RENDERER_H
#define RENDERER_H

#include "course.h"
#include "window.h"

class Renderer {
private:
    Course& course;
    Window& window;

    SDL_Renderer* sdl_renderer;
public:
    Renderer(Course& course, Window& window);
    int init();
    void render();
};

#endif // RENDERER_H
