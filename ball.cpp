#include "ball.h"

Ball::Ball(float x, float y, float radius) :
    position(glm::vec2(x, y)), velocity(glm::vec2(0, 0)), radius(radius) {}

Ball::Ball(glm::vec2 position, glm::vec2 velocity, float radius) :
    position(position), velocity(velocity), radius(radius) {}
