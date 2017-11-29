#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

class Color{
    uint8_t mR;
    uint8_t mG;
    uint8_t mB;

public:
    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b);

    uint16_t operator* (const Color& other) const;
    Color& operator*= (double k);

    Color& operator+= (const Color&);
};

Color operator* (const Color& c, double k);
Color operator+ (const Color& c1, const Color& c2);

#endif // COMMON_HPP
