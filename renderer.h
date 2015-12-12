#ifndef RENDERER_H
#define RENDERER_H

#include "course.h"
#include "window.h"

class Renderer {
private:
    Course& course;
    Window& window;
public:
    Renderer(Course& course, Window& window);
};

#endif // RENDERER_H
