#include "ball.h"

Ball::Ball(int x, int y) {
    position = glm::ivec2(x, y);
    velocity = glm::ivec2(1, 1);
}


