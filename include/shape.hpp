#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include "color.hpp"
#include "vector_3d.hpp"

class shape
{
    Color mColor;

public:
    shape();
    virtual ~shape();

    virtual std::vector<Point> findIntersections(const Ray& r) const = 0;
    virtual Vector_3d normal(const Point& p) const = 0;
};

#endif // SHAPE_HPP
