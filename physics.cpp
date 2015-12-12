#include <cstdio>

#include "physics.h"
#include "math.h"

void Physics::update(uint32_t elapsed) {
    float elapsed_s = elapsed / 1000.0;

    glm::vec2 new_position = ball.position + (ball.velocity * elapsed_s);

    std::vector<glm::vec2> vertices = course.vertices;
    for (std::vector<glm::vec2>::size_type i = 0; i < vertices.size(); i++) {
        int ia = i, ib = (i + 1) % vertices.size();
        glm::vec2 a = vertices[ia], b = vertices[ib];

        if (line_intersects_circle(a, b, new_position, ball.radius)) {
            new_position = ball.position;
            ball.velocity *= -1.0f;
        }
    }
    

    ball.position = new_position;
}
