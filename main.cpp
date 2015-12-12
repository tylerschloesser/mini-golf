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

    Window window(640, 480);
    assert(window.init() == 0);

    std::vector<glm::ivec2> vertices = {
        glm::ivec2(1,1),
        glm::ivec2(1,9),
        glm::ivec2(9,9),
        glm::ivec2(9,1)
    };
    Course course(10, 10, vertices);
    Ball ball(5, 5);

    Renderer renderer(course, ball, window);
    assert(renderer.init() == 0);

    Physics physics(course, ball);

    Game game(renderer);
    game.run();

    return 0;
}
