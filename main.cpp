#include <cstdio>

#include <glm/vec2.hpp>

#include "window.h"
#include "course.h"

int main(int argc, char* argv[]) {
    printf("hello world!\n");

    Window window;
    window.init(argc, argv);

    glm::vec2 vertices[] = {
        glm::vec2(1,1),
        glm::vec2(1,9),
        glm::vec2(9,9),
        glm::vec2(9,1)
    };
    Course course(10, 10, vertices);

    getchar();

    return 0;
}
