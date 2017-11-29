#ifndef RAY_H
#define RAY_H

#include "vector_3d.hpp"

class Ray
{
    Point mOrigin;
    Vector_3d mDirection;

public:
    Ray(const Point& p, const Vector_3d& v);

    Ray reflect(const Point& p, const Vector_3d& normal)&;
};


#endif // RAY_H
