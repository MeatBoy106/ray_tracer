#include "camera.hpp"

using namespace std;

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

    mSensor.resize(vResolution);
    for(auto& column: mSensor){
        column.resize(hResolution);
    }

    for(size_t y{0} ; y < mSensor.size() ; ++y){
        for(size_t x{0} ; x < mSensor[y].size() ; ++x){
            mSensor[y][x] = Pixel(Point(topLeft + h * x + v * y));
        }
    }
}


pair<size_t, size_t> Camera::getResolution() const
{
    return make_pair(mSensor.size(), mSensor[0].size());
}


Ray Camera::getRay(size_t x, size_t y) const
{
    return {mSensor[y][x], mSensor[y][x] - mCenter};
}


void Camera::setColor(size_t x, size_t y, Color c)
{
    mSensor[y][x].color = c;
}


ostream& operator <<(ostream& stream, const Camera& camera)
{
    for(auto& line: camera.mSensor){
        for(auto& p: line){
            stream << p.color << "  ";
        }
        stream << '\n';
    }

    return stream;
}
