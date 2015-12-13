#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
public:
    union {
        struct {
            uint8_t r, g, b, a;
        };
        uint32_t hex;
    };

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF) :
        r(r), g(g), b(b), a(a) {}

    static Color WHITE;
    static Color BLACK;
    static Color GRAY;
};

#endif // COLOR_H
