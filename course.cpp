#include <cstdio>
#include <cassert>

#include "course.h"

Course::Course(int width, int height, std::vector<glm::vec2> vertices) :
    width(width), height(height), vertices(vertices) {

    // width and height need to be the same until the ball can be properly scaled;
    assert(width == height);

    hole = glm::vec2(3, 3);
    hole_radius = 0.3f;

    // debug output
    fprintf(stderr, "Course initialized\n  width: %i\n  height: %i\n  vertices:\n", width, height);    
    for (glm::vec2& vertex : vertices) {
        fprintf(stderr, "    (%.1f, %.1f)\n", vertex[0], vertex[1]);
    }
}
