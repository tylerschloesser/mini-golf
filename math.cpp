#include <cmath>

#include "math.h"

bool line_intersects_circle(glm::vec2 l1, glm::vec2 l2, glm::vec2 c, float r) {
    glm::vec2 d = l2 - l1;
    glm::vec2 f = l1 - c;

    float a = glm::dot(d, d);
    float b = 2 * glm::dot(f, d);
    float c = glm::dot(f, f) - r * r;

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }

    discriminant = sqrt(discriminant);

    float t1 = (-b - discriminant) / (2 * a);
    float t1 = (-b + discriminant) / (2 * a);

    if (t1 >= 0 && t1 <= 1) {
        return true;
    }

    if (t2 >= 0 && t2 <= 1) {
        return true;
    }

    return false;
}
