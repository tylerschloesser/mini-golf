#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window(int width, int height) :
        width(width), height(height), sdl_window(NULL) {}
    ~Window();

    int width, height;
    SDL_Window* sdl_window;

    int init();
};

#endif // WINDOW_H
