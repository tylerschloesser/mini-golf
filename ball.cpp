#include "ball.h"

Ball::Ball(glm::vec2 position, glm::vec2 velocity, float radius) :
    position(position), velocity(velocity), radius(radius) {
    acceleration = glm::vec2(0, 0);
}
