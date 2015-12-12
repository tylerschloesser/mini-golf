#ifndef COURSE_H
#define COURSE_H

#include <vector>

#include <glm/vec2.hpp>

class Course {

public:
    int width, height;
    std::vector<glm::vec2> vertices;

    Course(int width, int height, std::vector<glm::vec2> vertices);
};

#endif // COURSE_H
