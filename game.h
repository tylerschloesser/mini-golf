#ifndef GAME_H
#define GAME_H

#include "renderer.h"

class Game {
private:
    uint32_t last_frame;
    uint32_t frame_time;

public:
    Renderer& renderer;
    Physics& physics;

    Game(Renderer& renderer, Physics& physics);

    void run();
};

#endif // GAME_H
