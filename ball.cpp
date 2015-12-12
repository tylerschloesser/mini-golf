#include "ball.h"

Ball::Ball(int x, int y) {
    position = glm::vec2(x, y);
    velocity = glm::vec2(1, 1);
}


