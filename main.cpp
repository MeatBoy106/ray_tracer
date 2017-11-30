#include <iostream>
#include "world.hpp"

using namespace std;

int main()
{
    World world("data/ex_world.txt");

    world.render();

    world.exportImage("data/ex_world.ppm");

    return 0;
}
