#include <glm/vec2.hpp>

class Course {

public:
    int width, height;
    glm::vec2* vertices;

    Course(int width, int height, glm::vec2* vertices):
        width(width), height(height), vertices(vertices) {};

};
