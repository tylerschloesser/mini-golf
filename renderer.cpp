#include <cstdio>

#include "renderer.h"

Renderer::Renderer(Course& course, Window& window) :
    course(course), window(window) {
    fprintf(stderr, "Renderer initialized");
}
