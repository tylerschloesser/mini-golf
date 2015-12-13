#include <glm/geometric.hpp>

#include "ball.h"

Ball::Ball(glm::vec2 position, glm::vec2 velocity, float radius) :
    position(position), velocity(velocity), radius(radius), color(Color::WHITE) {
    acceleration = glm::vec2(0, 0);
}

void Ball::stop() {
    velocity = acceleration = glm::vec2(0, 0);
}

bool Ball::is_moving() {
    return glm::length(velocity) > 0.0f && glm::length(acceleration) > 0.0f;
}
