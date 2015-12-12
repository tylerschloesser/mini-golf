#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
private:
    SDL_Window* sdl_window;
public:
    ~Window();
    int init(int argc, char* argv[]);
};

#endif // WINDOW_H
