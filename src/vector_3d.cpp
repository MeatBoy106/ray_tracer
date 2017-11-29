#include "vector_3d.hpp"

Vector_3d::Vector_3d(double x, double y, double z):
    x(x), y(y), z(z),
    norm(sqrt(x * x + y * y + z * z))
{}

Vector_3d Vector_3d::normalized() const
{
    return Vector_3d(x/norm, y/norm, z/norm);
}


Vector_3d& Vector_3d::operator+=(const Vector_3d& that)
{
    x += that.x;
    y += that.y;
    z += that.z;
    norm = sqrt(x * x + y * y + z * z);

    return *this;
}


Vector_3d& Vector_3d::operator-=(const Vector_3d& that)
{
    x -= that.x;
    y -= that.y;
    z -= that.z;
    norm = sqrt(x * x + y * y + z * z);

    return *this;
}

Vector_3d operator+(const Vector_3d& a, const Vector_3d& b)
{
    Vector_3d res(a);
    return res += b;
}


Vector_3d operator-(const Vector_3d& a, const Vector_3d& b)
{
    Vector_3d res(a);
    return res -= b;
}

Vector_3d& Vector_3d::operator*=(double k)
{
    x *= k;
    y *= k;
    z *= k;
    norm = sqrt(x * x + y * y + z * z);

    return *this;
}

Vector_3d operator*(const Vector_3d& a, double k)
{
    Vector_3d res(a);
    return res *= k;
}

Vector_3d operator/(const Vector_3d& a, double k)
{
    return a * (1/k);
}

