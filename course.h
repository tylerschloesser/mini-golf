#include <vector>

#include <glm/vec2.hpp>

class Course {

public:
    int width, height;
    std::vector<glm::ivec2> vertices;

    Course(int width, int height, std::vector<glm::ivec2> vertices);
};
