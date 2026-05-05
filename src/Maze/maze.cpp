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


int Maze::getWidth(){
    return width;
}

int Maze::getHeight(){
    return height;
}

bool corner_case(Maze *maze, int x, int y, CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();


    bool is_CTL = x % 4 == 0 && x == y && y < h/2;

    if (is_CTL){
        type = (x == 0) ? CellType::CORNER_TL : CellType::CORNER_RIGHT_DOWN;
    }


    return is_CTL;
}

void Maze::initMaze(Maze *maze){

    for (int y = 0; y < maze->height; y++) {

        maze->terrain[y] = new Cell[maze->width];

        for (int x = 0; x < maze->width; x++) {

            CellType type = CellType::EMPTY;
            if (corner_case(maze,x,y,type)) setTerrain(x, y, type);

            setTerrain(x, y, type);
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

            std::string end = " "; // "|"
            if( x == width - 1) end = "";

            cout << terrain[y][x].getType(false) << end;
        }

        cout << endl;
    }
}
