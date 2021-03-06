#ifndef COURSE_H
#define COURSE_H

#include <vector>

#include <glm/vec2.hpp>

class Course {

public:
    int width, height;
    std::vector<glm::vec2> vertices;

    glm::vec2 hole;
    float hole_radius;

    Course(int width, int height, std::vector<glm::vec2> vertices);
};

#endif // COURSE_H
