#include "sphere.hpp"

using namespace std;

Sphere::Sphere(const Point& center, double radius, const Color& color, double reflexion):
    Shape(color, reflexion),
    mCenter(center),
    mRadius(radius)
{}

vector<Point> Sphere::findIntersections(const Ray& r) const
{
    const Point &ro{r.origin},
                &mc{mCenter};
    const Vector_3d& rd{r.direction};

    //Solving aX² + bX + c = 0
    double a{rd.x * rd.x + rd.y * rd.y + rd.z * rd.z},
           b{2 * ((ro.x - mc.x) * rd.x +
                  (ro.y - mc.y) * rd.y +
                  (ro.z - mc.z) * rd.z)},
           c{(ro.x - mc.x) * (ro.x - mc.x) +
             (ro.y - mc.y) * (ro.y - mc.y) +
             (ro.z - mc.z) * (ro.z - mc.z) - mRadius * mRadius};

    double delta{b * b - 4 * a * c};

    if (delta < 0){
        return vector<Point>();
    } else {
        double sqrtDelta{sqrt(delta)};
        double k1{(-b - sqrtDelta) / 2 / a - epsilon},
               k2{(-b + sqrtDelta) / 2 / a - epsilon};
        if(k1 > 0 && k2 > 0){
            return vector<Point>{ro + rd * k1,
                                 ro + rd * k2};
        } else if (k1 > 0) {
            return vector<Point>{ro + rd * k1};
        } else if (k2 > 0) {
            return vector<Point>{ro + rd * k2};
        } else {
            return vector<Point>();
        }
    }
}

Vector_3d Sphere::normal(const Point& p) const
{
    return (p - mCenter).normalized();
}
