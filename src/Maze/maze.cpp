#include <cmath>
#include <iostream>
#include <string>

#include "maze.h"
#include "../Game/Game.h"
#include "maze_unicode.h"

using namespace std;


Maze::Maze(int _cx, int _cy, int _width, int _height){

    cx = _cx;
    cy = _cy;

    width = _width;
    height = _height;
}

void Maze::setTerrain(Maze *maze, int x, int y, const string& item){

}


void Maze::printTerrain(Maze *maze){

}
