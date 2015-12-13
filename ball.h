#ifndef BALL_H
#define BALL_H

#include <glm/vec2.hpp>

#include "color.h"

class Ball {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;

    Color color;
    glm::vec2 acceleration;

    Ball(glm::vec2 position, glm::vec2 velocity, float radius);

    void stop();
    bool is_moving();
};

#endif // BALL_H
