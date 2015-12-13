#include "ball.h"

Ball::Ball(int x, int y, float radius) {
    position = glm::vec2(x, y);
    velocity = glm::vec2(5, 5);
    this->radius = radius;
}


