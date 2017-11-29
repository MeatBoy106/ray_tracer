#include <fstream>
#include <cctype>
#include <limits>

#include "world.hpp"
#include "rayTracerExceptions.hpp"
#include "sphere.hpp"

#include <iostream>

using namespace std;

World::World(const string& sceneFile)
{
    parseSceneFile(sceneFile);
}

void World::parseSceneFile(const string& sceneFile)
{
    enum parserState{
        CAMERA_POSITION = 0,
        SCREEN_TOP_LEFT,
        SCREEN_TOP_RIGHT,
        SCREEN_BOT_LEFT,
        SCREEN_H_RESOLUTION,
        BACKGROUND_COLOR,
        LIGHT_POS_COLOR,
        SHAPES
    };

    ifstream file(sceneFile);

    if(!file){
        throw FileOpeningError(sceneFile);
    }

    auto findNextLine = [&file](){
        if(file.fail()){
            throw ParsingError();
        }
        //Flush the currently extracted line and then the commented or empty lines
        do{
            //Only the first line is not always ignored(1st condition)
            //The other lines are considered parsed and the end can be ignored (at least '\n')
            if(file.tellg() != 0 ||
               file.peek() == '#' ||
               file.peek() == '\n')
            {
                file.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(file.peek() == '#' || file.peek() == '\n');
    };

    parserState state(CAMERA_POSITION);

    Point observer, topLeft, topRight, botLeft;
    uint32_t hRes;

    while(true){
        findNextLine();
        if(file.eof()) break;

        double x, y, z, radius, reflex;
        uint32_t r, g, b;
        string shape;

        switch(state){
        case CAMERA_POSITION:
            file >> x >> y >> z;
            observer = Point(x, y, z);
            state = SCREEN_TOP_LEFT;
            break;

        case SCREEN_TOP_LEFT:
            file >> x >> y >> z;
            topLeft = Point(x, y, z);
            state = SCREEN_TOP_RIGHT;
            break;

        case SCREEN_TOP_RIGHT:
            file >> x >> y >> z;
            topRight = Point(x, y, z);
            state = SCREEN_BOT_LEFT;
            break;

        case SCREEN_BOT_LEFT:
            file >> x >> y >> z;
            botLeft = Point(x, y, z);
            state = SCREEN_H_RESOLUTION;
            break;

        case SCREEN_H_RESOLUTION:
            file >> hRes;
            state = BACKGROUND_COLOR;
            break;

        case BACKGROUND_COLOR:
            file >> r >> g >> b;
            mBackgroundColor = Color(r, g, b);
            state = LIGHT_POS_COLOR;
            break;

        case LIGHT_POS_COLOR:
            file >> x >> y >> z;
            file >> r >> g >> b;
            mLightPos = Point(x, y, z);
            mLightColor = Color(x, y, z);
            state = SHAPES;
            break;

        case SHAPES:
            file >> shape;
            if(shape == "sphere:"){
                file >> x >> y >> z >> radius
                     >> r >> g >> b >> reflex;
                Point center(x, y, z);
                Color color(r, g, b);
                mShapes.push_back(unique_ptr<Shape>(new Sphere(center, radius, color, reflex)));
            } else {
                throw ParsingError();
            }
            break;

        default: break;
        }
    }

    mCamera = Camera(observer, topLeft, topRight, botLeft, hRes);
}

void World::render()
{
    auto findIntersection = [](const decltype(mShapes)& shapes, const Ray& ray){
        bool found{false};
        Point resPoint;
        Shape const* resShape(nullptr);

        for(auto& shape: shapes){
            for(auto& i: shape->findIntersections(ray)){
                if(!found || (i - ray.origin).norm < (resPoint - ray.origin).norm){
                    found = true;
                    resPoint = i;
                    resShape = shape.get();
                }
            }
        }

        return make_tuple(found, resPoint, resShape);
    };


    function<Color(const Ray&, uint32_t)> computeRayColor =
        [this, &findIntersection, &computeRayColor](const Ray& ray, uint32_t recDepth) -> Color {
            auto iPrimary = findIntersection(this->mShapes, ray);

            bool interFound(std::get<0>(iPrimary));
            Point& interPoint(std::get<1>(iPrimary));
            Shape const* shape(std::get<2>(iPrimary));

            if(!interFound){
                return mBackgroundColor;
            }

            Vector_3d interNormal = shape->normal(interPoint);

            //Recursively compute the specular contribution
            Color specColor(shape->getReflexion() > 0 ?
                            computeRayColor(ray.reflect(interPoint, interNormal), recDepth - 1):
                            Color());

            //Light is visible if no intersection or intersection behind the light source
            auto iShadow = findIntersection(this->mShapes, Ray(interPoint, mLightPos - interPoint));
            bool interShadowFound = std::get<0>(iShadow);
            Point& interShadowPoint(std::get<1>(iShadow));

            Vector_3d interToLight(mLightPos - interPoint);
            bool lightVisible{!interShadowFound ||
                              (interShadowPoint - interPoint).norm > interToLight.norm};

            Color diffuColor(lightVisible ?
                             shape->getColor() * mLightColor * interNormal.scalar(interToLight.normalized()) * (1 - shape->getReflexion()) * (1 / 255.):
                             Color());

            return specColor + diffuColor;
        };

    auto res = mCamera.getResolution();
    for(size_t x{0} ; x < res.first ; x++){
        for(size_t y{0} ; y < res.second ; y++){
            const auto& primRay = mCamera.getRay(x, y);
            mCamera.setColor(x, y, computeRayColor(primRay, 5));
        }
    }
}


void World::exportImage(const std::string& output) const
{
    ofstream outImage(output);
    if(!outImage){
        throw(FileOpeningError(output));
    }

    auto resolution = mCamera.getResolution();
    outImage << "P3" << '\n'
             << resolution.first << " " << resolution.second << '\n';

    outImage << mCamera;
}
