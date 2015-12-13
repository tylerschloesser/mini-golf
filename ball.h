#ifndef BALL_H
#define BALL_H

#include <glm/vec2.hpp>

class Ball {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    Ball(float x, float y, float radius);
    Ball(glm::vec2 position, glm::vec2 velocity, float radius);
};

#endif // BALL_H
