#ifndef SPHERE_H
#define SPHERE_H

#include "vector_3d.hpp"
#include "shape.hpp"

class Sphere : public Shape
{
    Point mCenter;
    double mRadius;

public:
    Sphere(const Point& center, double radius);
    virtual ~Sphere();

    virtual std::vector<Point> findIntersections(const Ray& r) const;
    virtual Vector_3d normal(const Point& p) const;
};

#endif // SPHERE_H
