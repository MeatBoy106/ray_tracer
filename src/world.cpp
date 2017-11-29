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

    parserState state{CAMERA_POSITION};

    Point observer, topLeft, topRight, botLeft;
    uint32_t hRes;

    while(!file.eof()){
        findNextLine();

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
