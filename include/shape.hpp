#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include "color.hpp"
#include "vector_3d.hpp"
#include "ray.hpp"

extern double const epsilon;

class Shape
{
    Color mColor;
    double mReflexion;

public:
    Shape(const Color& color, double reflexion);
    virtual ~Shape() = default;

    Color getColor() const {return mColor;}
    double getReflexion() const {return mReflexion;}

    virtual std::pair<bool, Point> findIntersection(const Ray &r) const = 0;
    virtual Vector_3d normal(const Point& p) const = 0;
};

#endif // SHAPE_HPP
