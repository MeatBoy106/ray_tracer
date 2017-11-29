#include <fstream>
#include "world.hpp"
#include "rayTracerException.hpp"

using namespace std;

World::World(const string& sceneFile);
{
    parseSceneFile(sceneFile);
}

World::~World()
{}

void World::parseSceneFile(const string& scenefile)
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
    }

    ifstream file(scenefile);

    auto testParseFail = [&file](){
        if(file.fail()){
            throw ParsingError;
        }
    };

    auto ignoreComments = [&file](){
        testParseFail();
        while(file.peek( == '#')){
            file.ignore(std::numeric_limits<std::streamsize>::max())
        }
    }

    if(!scenefile){
        throw FileOpeningError(scenefile);
    }

    parserState state{CAMERA_POSITION};

    while(!scenefile.eof()){
        ignoreComments();

        switch(state){
        case CAMERA_POSITION:
            double x, y, z;
            cin >> x >> y >> z;
            mCamera(x, y, z);
            break;

        case SCREEN_TOP_LEFT:
            double x, y, z;
            cin >> x >> y >> z;
            mScreenTopLeft(x, y, z);
            break;

        case SCREEN_TOP_RIGHT:
            double x, y, z;
            cin >> x >> y >> z;
            mScreenTopRight(x, y, z);
            break;

        case SCREEN_BOT_LEFT:
            double x, y, z;
            cin >> x >> y >> z;
            mScreenBotLeft(x, y, z);
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
