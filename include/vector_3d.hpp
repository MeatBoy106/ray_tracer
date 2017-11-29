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


    Vector_3d& operator+=(const Vector_3d& that);
    Vector_3d& operator-=(const Vector_3d& that);
    Vector_3d& operator*=(double k);
    Vector_3d& operator/=(double k){return (*this *= (1/k));}


    Vector_3d normalized() const;
};

Vector_3d operator+(const Vector_3d& a, const Vector_3d& b);
Vector_3d operator-(const Vector_3d& a, const Vector_3d& b);
Vector_3d operator*(const Vector_3d& a, double k);
Vector_3d operator/(const Vector_3d& a, double k);


using Point = Vector_3d;

#endif // VECTOR_3D_H
