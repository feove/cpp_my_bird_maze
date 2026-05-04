#include <cmath>
#include <iostream>
#include <string>

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

    for (int y = 0; y < height; y++) {

        terrain[y] = new Cell[width];

        for (int x = 0; x < width; x++) {

            terrain[y][x] = Cell(x, y, CellType::EMPTY);
        }
    }
}

void Maze::setTerrain(Maze *maze, int x, int y, const string& item){

}


void Maze::printTerrain(Maze *maze){

}
