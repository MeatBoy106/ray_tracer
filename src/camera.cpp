#include "camera.hpp"

Camera::Camera(const Point& observer,
               const Point& topLeft,
               const Point& topRight,
               const Point& botLeft,
               uint32_t hResolution):
    mCenter(observer)
{
    Vector_3d h((topRight - topLeft) / hResolution),
              v((botLeft - topLeft) / (botLeft - topLeft).norm * h.norm);

    uint32_t vResolution = static_cast<uint32_t>(hResolution * ((botLeft - topLeft).norm / (topRight - topLeft).norm));

    mSensor.resize(hResolution);
    for(auto& column: mSensor){
        column.resize(vResolution);
    }

    for(size_t x{0} ; x < mSensor.size() ; ++x){
        for(size_t y{0} ; y < mSensor.size() ; ++y){
            mSensor[x][y] = Pixel(Point(topLeft + h * x + v * y));
        }
    }
}


Ray Camera::getRay(size_t x, size_t y)
{
    return Ray(mSensor[x][y], mSensor[x][y] - mCenter);
}

void Camera::setColor(size_t x, size_t y, Color c)
{
    mSensor[x][y].color = c;
}
