#ifndef COMMON_HPP
#define COMMON_HPP

#include <ostream>
#include <cstdint>

class Color{
    friend std::ostream& operator <<(std::ostream& stream, const Color& color);

    uint32_t mR;
    uint32_t mG;
    uint32_t mB;

private:
    void bound();

public:
    Color() = default;
    Color(uint32_t r, uint32_t g, uint32_t b);

    Color& operator*= (double k);
    Color& operator*= (const Color& that);

    Color& operator+= (const Color&);
};

Color operator* (const Color& c, double k);
Color operator* (const Color& c1, const Color& c2);
Color operator+ (const Color& c1, const Color& c2);

#endif // COMMON_HPP
