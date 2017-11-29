#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <ostream>
#include "color.hpp"
#include "vector_3d.hpp"

class Pixel
{
    Point position;

    uint32_t mX;
    uint32_t mY;

    Color mColor;

public:
    Pixel(uint32_t x, uint32_t y, Color c);
};

std::ostream& operator <<(std::ofstream& os, const Pixel& p);

#endif // PIXEL_HPP
