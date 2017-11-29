#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <ostream>
#include "Color.hpp"

class Pixel
{
    uint32_t mX;
    uint32_t mY;
    Color mColor;

public:
    Pixel(uint32_t x, uint32_t y, Color c);
};

std::ostream& operator <<(std::ofstream& os, const Pixel& p);

#endif // PIXEL_HPP
