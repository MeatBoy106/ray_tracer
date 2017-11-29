#include "vector_3d.hpp"

Vector_3d::Vector_3d(double x, double y, double z):
    x(x), y(y), z(z),
    norm(sqrt(x * x + y * y + z * z))
{}

Vector_3d Vector_3d::normalized() const
{
    return Vector_3d(x/norm, y/norm, z/norm);
}
