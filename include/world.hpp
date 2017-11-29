#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
#include <memory>
#include "vector_3d.hpp"
#include "shape.hpp"
#include "pixel.hpp"
#include "camera.hpp"

class World
{
    Camera mCamera;

    Point mLightPos;
    Color mLightColor;

    Color mBackgroundColor;

    std::vector<std::unique_ptr<Shape>> mShapes;

private:
    void parseSceneFile(const std::string& sceneFile);

public:
    World(const std::string& sceneFile);
};

#endif // WORLD_HPP
