#include <fstream>
#include <cctype>
#include <limits>

#include "world.hpp"
#include "rayTracerExceptions.hpp"

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

    auto findNextLine = [&file](){
        if(file.fail()){
            throw ParsingError();
        }
        //Flush the currently extracted line
        do{
            //The first line shall not be flushed directly
            if(file.tellg() != 0){
                file.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(file.peek() == '#');
    };

    if(!file){
        throw FileOpeningError(sceneFile);
    }

    parserState state{CAMERA_POSITION};

    Point observer, topLeft, topRight, botLeft;

    while(!file.eof()){
        findNextLine();

        switch(state){
            double x, y, z;
            //uint8_t r, g, b;

        case CAMERA_POSITION:
            file >> x >> y >> z;
            observer = Point(x, y, z);
            break;

        case SCREEN_TOP_LEFT:
            file >> x >> y >> z;
            topLeft = Point(x, y, z);
            break;

        case SCREEN_TOP_RIGHT:
            file >> x >> y >> z;
            topRight = Point(x, y, z);
            break;

        case SCREEN_BOT_LEFT:
            file >> x >> y >> z;
            botLeft = Point(x, y, z);
            break;

        case SCREEN_H_RESOLUTION:
            break;

        case BACKGROUND_COLOR:
            break;

        case LIGHT_POS_COLOR:
            break;

        default: break;
        }
    }
}
