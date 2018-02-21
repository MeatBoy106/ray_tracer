#include <cmath>
#include "ray.hpp"

using namespace std;

Ray::Ray(const Point& p, const Vector_3d& v):
    origin(p),
    direction(v.normalized())
{}

Ray Ray::reflect(const Point& p, const Vector_3d& normal) const
{
    return {p, direction - normal * 2 * (direction.dotProduct(normal))};
}
