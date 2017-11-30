#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <ostream>
#include "color.hpp"
#include "vector_3d.hpp"

struct Pixel : public Point
{
    Color color;

    Pixel() = default;
    Pixel(const Point& p, Color c = Color());
};

std::ostream& operator <<(std::ofstream& os, const Pixel& p);

#endif // PIXEL_HPP
