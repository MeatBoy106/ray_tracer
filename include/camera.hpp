#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "pixel.hpp"
#include "ray.hpp"

class Camera
{
    Point mCenter;
    std::vector<std::vector<Pixel>> mSensor;

public:
    Camera() = default;
    Camera(const Point& observer,
           const Point& topLeft,
           const Point& topRight,
           const Point& botLeft,
           uint32_t hResolution);

    Ray getRay(size_t x, size_t y);
    void setColor(size_t x, size_t y, Color c);
};

#endif // CAMERA_HPP
