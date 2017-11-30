#include "shape.hpp"

double const epsilon = 1e-6;

Shape::Shape(const Color& color, double reflexion):
    mColor(color),
    mReflexion(reflexion)
{}
