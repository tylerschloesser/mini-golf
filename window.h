#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    SDL_Window* sdl_window;

    ~Window();
    int init();
};

#endif // WINDOW_H
