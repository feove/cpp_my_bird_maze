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

bool is_inside(int x, int y,int wlimit,int hlimit){

    return x < wlimit && y < hlimit;
}

bool are_zero(int x, int y){
    return x == 0 && y == 0;
}

bool is_corner(Maze *maze,int x, int y, int wl, int hl, bool (*f)(int,int,int,int),CellType &type,CellType special,CellType normal){


    bool is_Corner = x == 0 && y == 0;

    if (is_Corner){
         type = special;
         return true;
    }

    if (x == y && x % 2 == 0 &&  y % 2 == 0){

        if ( f(x,y,wl,hl)){

            type = normal;
        }
    }

    return false;
}

bool corner_case(Maze *maze, int x, int y, CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();

    if (is_corner(maze, x, y, w/2, h/2, is_inside, type,CellType::CORNER_TL, CellType::CORNER_LEFT_DOWN)) return true;

    return false;
}

void Maze::initMaze(Maze *maze){

    for (int y = 0; y < maze->height; y++) {

        maze->terrain[y] = new Cell[maze->width];

        for (int x = 0; x < maze->width; x++) {

            CellType type = CellType::WALL_HORIZONTAL;
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
