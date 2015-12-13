#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "line.h"

class Game {
private:
    uint32_t last_frame;
    uint32_t frame_time;

    void handle_mouse_click(SDL_MouseButtonEvent event);

    void update(uint32_t elapsed);

    Line* shot_line;

public:
    Renderer& renderer;
    Physics& physics;

    Game(Renderer& renderer, Physics& physics);

    void run();
};

#endif // GAME_H
