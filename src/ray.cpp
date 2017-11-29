#include <cmath>
#include "ray.hpp"

using namespace std;

Ray::Ray(const Point& p, const Vector_3d& v):
    mOrigin(p),
    mDirection(v.normalized())
{}
