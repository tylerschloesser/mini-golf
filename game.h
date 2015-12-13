#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "line.h"

class Game {
private:
    Renderer& renderer;
    Physics& physics;
    Ball& ball;

    uint32_t last_frame;
    uint32_t frame_time;

    void handle_mouse_click(SDL_MouseButtonEvent event);
    void handle_mouse_motion(SDL_MouseMotionEvent event);

    void update(uint32_t elapsed);

    Line* shot_line;
public:
    Game(Renderer& renderer, Physics& physics, Ball& ball);
    void run();
};

#endif // GAME_H
