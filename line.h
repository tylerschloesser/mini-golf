#ifndef LINE_H
#define LINE_H

#include <glm/vec2.hpp>

#include "color.h"

class Line {
public:
    glm::vec2 a, b;
    Color color;
    bool visible;

    glm::vec2 translate;

    Line(glm::vec2 a = glm::vec2(), glm::vec2 b = glm::vec2(), Color color = Color::BLACK, bool visible = true) :
        a(a), b(b), color(color), visible(visible) {
        translate = glm::vec2(0, 0);
    }
};

#endif // LINE_H
