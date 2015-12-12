#include <cstdio>
#include <cassert>

#include "window.h"

Window::Window(int width, int height) : width(width), height(height), sdl_window(NULL) {
    // width and height need to be the same until the ball can be properly scaled;
    assert(width == height);
    fprintf(stderr, "Window created\n  width: %d\n  height: %d\n", width, height);
}

int Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        return 1;
    }

    sdl_window = SDL_CreateWindow(
        "test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL);

    if (sdl_window == NULL) {
        fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError());
        return 1;
    }

    fprintf(stderr, "Window initialized\n");

    return 0;
}

Window::~Window() {
    if (sdl_window == NULL) {
        return;
    }
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}
