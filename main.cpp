#include <vector>
#include <cstdio>
#include <cassert>

#include <glm/vec2.hpp>

#include "window.h"
#include "course.h"
#include "ball.h"
#include "renderer.h"
#include "physics.h"
#include "game.h"

int main(int argc, char* argv[]) {

    Window window(500, 500);
    assert(window.init() == 0);

    //std::vector<glm::vec2> vertices = {
    //    glm::vec2(1,1),
    //    glm::vec2(1,9),
    //    glm::vec2(9,9),
    //    glm::vec2(9,1)
    //};

    std::vector<glm::vec2> vertices = {
        glm::vec2(1,1),
        glm::vec2(2,9),
        glm::vec2(8,8),
        glm::vec2(9,2)
    };

    Course course(10, 10, vertices);
    Ball ball(5, 5, .5);

    Renderer renderer(course, ball, window);
    assert(renderer.init() == 0);

    Physics physics(course, ball);

    Game game(renderer, physics);
    game.run();

    return 0;
}
