#include "sphere.hpp"

using namespace std;

Sphere::Sphere(const Point& center, double radius, const Color& color, double reflexion):
    Shape(color, reflexion),
    mCenter(center),
    mRadius(radius)
{}

vector<Point> Sphere::findIntersections(const Ray& r) const
{
    auto squared = [](double x){return x * x;};
    //Solving aX² + bX + c = 0

    const Point &ro{r.origin},
                &mc{mCenter};
    const Vector_3d& rd{r.direction};

    double a{squared(rd.x) + squared(rd.y) + squared(rd.z)},
           b{2 * ((ro.x - mc.x) * rd.x +
                  (ro.y - mc.y) * rd.y +
                  (ro.z - mc.z) * rd.z)},
           c{squared(ro.x - mc.x) +
             squared(ro.y - mc.y) +
             squared(ro.z - mc.z) - mRadius};

    double delta = squared(b) - 4 * a * c;

    if (delta < 0){
        return vector<Point>();
    } else {
        double k1{(-b - sqrt(delta)) / 2 / a - epsilon},
               k2{(-b + sqrt(delta)) / 2 / a - epsilon};

        return vector<Point>{ro + rd * k1,
                             ro + rd * k2};
    }
}

Vector_3d Sphere::normal(const Point& p) const
{
    return (p - mCenter).normalized();
}
