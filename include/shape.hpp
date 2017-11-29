#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include "color.hpp"
#include "vector_3d.hpp"
#include "ray.hpp"

class Shape
{
    Color mColor;

public:
    Shape(const Color& color);
    virtual ~Shape() = default;

    virtual std::vector<Point> findIntersections(const Ray& r) const = 0;
    virtual Vector_3d normal(const Point& p) const = 0;
};

#endif // SHAPE_HPP
