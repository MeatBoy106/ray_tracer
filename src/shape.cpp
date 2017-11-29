#include "shape.hpp"

extern double const epsilon = 1e-9;

Shape::Shape(const Color& color, double reflexion):
    mColor(color),
    mReflexion(reflexion)
{}
