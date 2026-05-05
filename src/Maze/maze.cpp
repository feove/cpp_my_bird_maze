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

bool tl_area(Maze *maze,int x, int y){

    int w = maze->getWidth();
    int h = maze->getHeight();

    return x == y  && x < w/2 && y < h/2;
}

bool tr_area(Maze *maze,int x, int y){

    int w = maze->getWidth();
    int h = maze->getHeight();

    return w-y == x && x > w/2 && y < h/2;
}


bool bl_area(Maze *maze,int x, int y){

    int w = maze->getWidth();
    int h = maze->getHeight();

    return y == h-x  && x < w/2 && y > h/2;
}


bool br_area(Maze *maze,int x, int y){

    int w = maze->getWidth();
    int h = maze->getHeight();

    return x == y && x > w/2 && y > h/2;
}

//Too much args
bool is_corner(Maze *maze,int x, int y, bool (*f)(Maze *maze,int,int),CellType &type,CellType new_type){

    if (type != CellType::EMPTY) return true;

    if (x % 2 == 0 &&  y % 2 == 0){

        if (f(maze,x,y)){

            type = new_type;
            return true;
        }
    }

    return false;
}

bool corner_case(Maze *maze, int x, int y, CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();

   //TOP LEFT CORNER
    type = (x == 0 && y == 0) ? CellType::CORNER_TL : type;
    if (is_corner(maze, x, y, tl_area, type, CellType::CORNER_TL_SINGLE)) return true;


    //TOP RIGHT CORNER
    type = (x == w-1 && y == 0) ? CellType::CORNER_TR : type;
    if (is_corner(maze, x+1, y, tr_area, type, CellType::CORNER_TR_SINGLE)) return true;

    //BOTTOM LEFT CORNER
    type = (x == 0 && y == h-1) ? CellType::CORNER_BL : type;
    if (is_corner(maze, x, y+1, bl_area, type, CellType::CORNER_BL_SINGLE)) return true;


    //BOTTOM RIGHT CORNER
    type = (x == w-1 && y == h-1) ? CellType::CORNER_BR : type;
    if (is_corner(maze, x+1, y+1, br_area, type, CellType::CORNER_BR_SINGLE)) return true;


    return false;
}

bool horizontal_wall(Maze *maze,int x,int y,CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();

    //HORIZONTAL WALLS
    if (x != w-1 && x != 0){

        //TOP
        if (y < h/2 && x > y && x < w-y && y % 2 == 0){

            type = (y == 0) ? CellType::WALL_HORIZONTAL : CellType::LINE_HORIZONTAL;
            return true;
        }

         //BOTTOM
        if (y > h/2 && y > x && h-x-1 < y && y % 2 == 1){

            type = (y == h-1) ? CellType::WALL_HORIZONTAL : CellType::LINE_HORIZONTAL;
            return true;
        }
    }

    return false;
}

bool vertical_walls(Maze *maze,int x,int y,CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();

    //VERTICAL WALLS
    if (y != h-1 && y != 0){

        //LEFT
        if (x < h/2 && y > x && x < w-y && x % 2 == 0){

            type = (x == 0) ? CellType::WALL_VERTICAL : CellType::LINE_VERTICAL;
            return true;
        }

        //RIGHT
        if (x > h/2 && y < x && y > h-x-1 && x % 2 == 1){

            type = (x == w-1) ? CellType::WALL_VERTICAL : CellType::LINE_VERTICAL;
            return true;
        }
    }

    return false;

}
bool wall_case(Maze *maze,int x,int y,CellType &type){

    if (horizontal_wall(maze,x, y, type)) return true;

    if (vertical_walls(maze, x,  y, type)) return true;

    return false;
}

void Maze::initMaze(Maze *maze){

    for (int y = 0; y < maze->height; y++) {

        maze->terrain[y] = new Cell[maze->width];

        for (int x = 0; x < maze->width; x++) {

            CellType type = CellType::EMPTY;
            if (corner_case(maze,x,y,type)){
                setTerrain(x, y, type);
                continue;
            }

            if (wall_case(maze,x,y,type)){
                setTerrain(x, y, type);
                continue;
            }

            //type = CellType::WALL_HORIZONTAL;
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

            std::string u = terrain[y][x].getType(true);

            std::string res = ((x % 2 == 0 && x < width/2) || (x % 2 == 1 && x > width/2)) ? u : u+u+u+u;

            cout << res;
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
