#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color {
public:
    uint8_t r, g, b, a;    
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xFF) :
        r(r), g(g), b(b), a(a) {}
    
    static Color WHITE;
};

#endif // COLOR_H
