#ifndef SPHERE_H
#define SPHERE_H

#include "vector_3d.hpp"
#include "shape.hpp"

class Sphere : public Shape
{
    Point mCenter;
    double mRadius;

public:
    Sphere(const Point& center, double radius, const Color& color, double reflexion);

    ~Sphere() override = default;

    std::vector<Point> findIntersections(const Ray& r) const override;

    Vector_3d normal(const Point& p) const override;
};

#endif // SPHERE_H
