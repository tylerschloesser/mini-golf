#ifndef BALL_H
#define BALL_H

#include <glm/vec2.hpp>

class Ball {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    Ball(int x, int y);
};

#endif // BALL_H
