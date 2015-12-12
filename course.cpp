#include <cstdio>

#include "course.h"

Course::Course(int width, int height, std::vector<glm::ivec2> vertices) :
    width(width), height(height), vertices(vertices) {

    // debug output
    fprintf(stderr, "Course initialized\n  width: %i\n  height: %i\n  vertices:\n", width, height);    
    for (glm::ivec2& vertex : vertices) {
        fprintf(stderr, "    (%i, %i)\n", vertex[0], vertex[1]);
    }
}
