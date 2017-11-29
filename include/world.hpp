#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
#include <memory>
#include "vector_3d.hpp"
#include "shape.hpp"

class World
{
    Point mCamera;

    Point mScreenTopLeft,
          mScreenTopRigh,
          mScreenBotLeft;
    std::vector<Pixel> mScreen;

    Point mLightSource;
    Color mLightSourceColor;

    Color mBackgroundColor;

    std::vector<std::unique_ptr<Shape>> mShapes;

private:
    void parseSceneFile(const std::string& sceneFile);

public:
    World(const std::string& sceneFile);
};

#endif // WORLD_HPP
