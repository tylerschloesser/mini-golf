#ifndef BALL_H
#define BALL_H

#include <glm/vec2.hpp>

class Ball {
public:
    glm::ivec2 position;
    glm::ivec2 velocity;
    Ball(int x, int y);
};

#endif // BALL_H
