#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <ostream>
#include <vector>
#include <utility>
#include "pixel.hpp"
#include "ray.hpp"

class Camera
{
    friend std::ostream& operator <<(std::ostream& stream, const Camera& camera);

    Point mCenter;
    std::vector<std::vector<Pixel>> mSensor;

public:
    Camera() = default;
    Camera(const Point& observer,
           const Point& topLeft,
           const Point& topRight,
           const Point& botLeft,
           uint32_t hResolution);

    std::pair<size_t, size_t> getResolution() const;
    Ray getRay(size_t x, size_t y) const;
    void setColor(size_t x, size_t y, Color c);
};

std::ostream& operator <<(std::ostream& stream, const Camera& camera);

#endif // CAMERA_HPP
