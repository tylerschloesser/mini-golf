#include "physics.h"

void Physics::update(uint32_t elapsed) {
    float elapsed_s = elapsed / 1000.0;
    ball.position += (ball.velocity * elapsed_s);
}
