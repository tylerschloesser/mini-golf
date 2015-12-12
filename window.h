#include <SDL2/SDL.h>

class Window {
private:
    SDL_Window* sdl_window;
public:
    ~Window();
    int init(int argc, char* argv[]);
};
