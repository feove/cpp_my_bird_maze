#include <cmath>
#include <iostream>
#include <string>
#include <type_traits>

#include "maze.h"
#include "../Game/Game.h"
#include "cell.h"
#include "maze_unicode.h"

using namespace std;

Maze::Maze(int _cx, int _cy, int _width, int _height){

    cx = _cx;
    cy = _cy;

    width = _width;
    height = _height;

    //std::unique_ptr<Cell*[]> terrain;

    terrain = std::make_unique<Cell*[]>(height);

    initMaze(this);
}



void Maze::initMaze(Maze *maze){


    for (int y = 0; y < maze->height; y++) {

        maze->terrain[y] = new Cell[maze->width];

        for (int x = 0; x < maze->width; x++) {

            if (y == 0){

                setTerrain(x, y,CellType::WALL_HORIZONTAL);
                continue;
            }

            setTerrain( x,y, CellType::EMPTY);
        }
    }
}


void Maze::setTerrain(int x, int y, CellType type){

    terrain[y][x] = Cell(x,y,type);
}


void Maze::printTerrain(){

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            cout << terrain[y][x].getType(true);
        }

        cout << endl;
    }
}

void Maze::printBackend(){

    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            cout << "[" << terrain[y][x].getType(false) << "]";
        }

        cout << endl;
    }
}
