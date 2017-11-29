#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <cmath>
#include <array>


struct Vector_3d
{
    double x;
    double y;
    double z;
    double norm;

    Vector_3d() = default;
    Vector_3d(const Vector_3d&) = default;
    Vector_3d(double x, double y, double z);

    Vector_3d& operator=(const Vector_3d&) = default;

    Vector_3d normalized() const;
};


using Point = Vector_3d;

#endif // VECTOR_3D_H
