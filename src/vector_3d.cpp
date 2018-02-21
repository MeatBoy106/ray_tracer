#include "vector_3d.hpp"

Vector_3d::Vector_3d(double x, double y, double z):
    x(x), y(y), z(z),
    norm(sqrt(x * x + y * y + z * z))
{}

Vector_3d Vector_3d::normalized() const
{
    return {x/norm, y/norm, z/norm};
}

Vector_3d operator+(const Vector_3d& a, const Vector_3d& b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}


Vector_3d operator-(const Vector_3d& a, const Vector_3d& b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}


double Vector_3d::dotProduct(const Vector_3d &that) const
{
    return x * that.x + y * that.y + z * that.z;
}


Vector_3d operator*(const Vector_3d& a, double k)
{
    return {a.x * k, a.y * k, a.z * k};
}

Vector_3d operator/(const Vector_3d& a, double k)
{
    return {a.x / k, a.y / k, a.z / k};
}

