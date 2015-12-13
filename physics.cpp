#include <cstdio>

#include <glm/geometric.hpp>
#include <glm/trigonometric.hpp>
#include <glm/mat2x2.hpp>
//#include <glm/gtx/rotate_vector.hpp>

#include "physics.h"
#include "math.h"

void Physics::update(uint32_t elapsed) {
    float elapsed_s = elapsed / 1000.0;

    if (glm::length(ball.velocity) <= 0.1f) {
        // TODO this only makes sense because acceleration is actually friction
        ball.stop();
        return;
    }

    ball.velocity += ball.acceleration * elapsed_s;

    glm::vec2 new_position = ball.position + (ball.velocity * elapsed_s);

    std::vector<glm::vec2> vertices = course.vertices;
    for (std::vector<glm::vec2>::size_type i = 0; i < vertices.size(); i++) {
        int ia = i, ib = (i + 1) % vertices.size();
        glm::vec2 a = vertices[ia], b = vertices[ib];

        // TODO handle intersecting multiple lines
        if (line_intersects_circle(a, b, new_position, ball.radius)) {

            glm::vec2 v1 = glm::normalize(ball.velocity);
            glm::vec2 v2 = glm::normalize(a - b);
            float dot = glm::dot(v1, v2);
            float angle = acos(dot) * 2;

            float dampening = 0.95f;
            ball.velocity =
                glm::mat2x2(cos(angle), sin(angle), -sin(angle), cos(angle)) * (ball.velocity * dampening);

            float friction = 0.99f;
            ball.acceleration = glm::normalize(-ball.velocity) * friction;

            new_position = ball.position;
        }
    }

    ball.position = new_position;
}
