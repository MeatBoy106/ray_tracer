#include "sphere.hpp"

using namespace std;

Sphere::Sphere(const Point& center, double radius, const Color& color, double reflexion):
    Shape(color, reflexion),
    mCenter(center),
    mRadius(radius)
{}

vector<Point> Sphere::findIntersections(const Ray& r) const
{
    return vector<Point>();
}

Vector_3d Sphere::normal(const Point& p) const
{
    return Vector_3d();
}
