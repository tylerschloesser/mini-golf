#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window(int width, int height);
    ~Window();

    int width, height;
    SDL_Window* sdl_window;

    int init();
};

#endif // WINDOW_H
