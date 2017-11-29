#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "pixel.hpp"

class Camera
{
    std::vector<std::vector<Pixel>> mSensor;

public:
    Camera() = default;
    Camera(const Point& observer,
           const Point& topLeft,
           const Point& topRight,
           const Point& botLeft);
};

#endif // CAMERA_HPP
