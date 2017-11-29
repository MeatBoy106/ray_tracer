#ifndef COMMON_HPP
#define COMMON_HPP

#include <ostream>
#include <cstdint>

class Color{
    friend std::ostream& operator <<(std::ostream& stream, const Color& color);

    uint8_t mR;
    uint8_t mG;
    uint8_t mB;

public:
    Color() = default;
    Color(uint8_t r, uint8_t g, uint8_t b);

    Color& operator*= (double k);
    Color& operator*= (const Color& that);

    Color& operator+= (const Color&);
};

Color operator* (const Color& c, double k);
Color operator* (const Color& c1, const Color& c2);
Color operator+ (const Color& c1, const Color& c2);

std::ostream& operator <<(std::ostream& stream, const Color& color);

#endif // COMMON_HPP
