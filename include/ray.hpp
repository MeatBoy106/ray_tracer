#ifndef RAY_H
#define RAY_H

#include "vector_3d.hpp"

struct Ray
{
    const Point origin;
    const Vector_3d direction;

    Ray(const Point& p, const Vector_3d& v);

    Ray reflect(const Point& p, const Vector_3d& normal);
};


#endif // RAY_H
