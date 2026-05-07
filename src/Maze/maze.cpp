#include <cmath>
#include <iostream>
#include <string>
#include <type_traits>

#include "maze.h"
#include "../Game/Game.h"
#include "cell.h"
#include "maze_unicode.h"

using namespace std;

struct PrintContext {
    int &x;
    int &y;

    int w;
    int h;

    Cell cell;
};

struct WallContext {

    Maze* maze;

    int x;
    int y;

    CellType& type;
};

struct CornerContext : WallContext {

    CellType new_type;

    bool (*area_check)(Maze*, int, int);
};


int Maze::getX(){
    return x;
}

int Maze::getY(){
    return y;
}

Maze::Maze(int _cx, int _cy,int _x, int _y, int _width, int _height){

    cx = _cx;
    cy = _cy;

    x = _x;
    y = _y;

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

bool is_corner(const CornerContext& ctx) {

    if (ctx.type != CellType::EMPTY) return true;

    if (ctx.x % 2 == 0 && ctx.y % 2 == 0) {

        if (ctx.area_check(ctx.maze, ctx.x, ctx.y)) {

            ctx.type = ctx.new_type;
            return true;
        }
    }

    return false;
}


bool horizontal_wall(WallContext& ctx){

    int w = ctx.maze->getWidth();
    int h = ctx.maze->getHeight();
    int x = ctx.x;
    int y = ctx.y;
    CellType& type = ctx.type;

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

bool vertical_walls(WallContext& ctx){

    int w = ctx.maze->getWidth();
    int h = ctx.maze->getHeight();
    int x = ctx.x;
    int y = ctx.y;
    CellType& type = ctx.type;
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

bool wall_cases(Maze *maze,int x,int y,CellType &type){

    WallContext ctx{
        maze,
        x,
        y,
        type
    };

    if (horizontal_wall(ctx)) return true;

    if (vertical_walls(ctx)) return true;

    return false;
}


bool corner_cases(Maze *maze, int x, int y, CellType &type){

    int w = maze->getWidth();
    int h = maze->getHeight();

    CornerContext ctx{
        maze,
        x,
        y,
        type
    };

   //TOP LEFT CORNER
    type = (x == 0 && y == 0) ? CellType::CORNER_TL : type;
    ctx.new_type = CellType::CORNER_TL_SINGLE;
    ctx.area_check = tl_area;
    if (is_corner(ctx)) return true;


    //TOP RIGHT CORNER
    type = (x == w-1 && y == 0) ? CellType::CORNER_TR : type;
    ctx.x = x+1;
    ctx.new_type = CellType::CORNER_TR_SINGLE;
    ctx.area_check = tr_area;
    if (is_corner(ctx)) return true;

    //BOTTOM LEFT CORNER
    type = (x == 0 && y == h-1) ? CellType::CORNER_BL : type;
    ctx.x = x;
    ctx.y = y+1;
    ctx.new_type = CellType::CORNER_BL_SINGLE;
    ctx.area_check = bl_area;
    if (is_corner(ctx)) return true;


    //BOTTOM RIGHT CORNER
    type = (x == w-1 && y == h-1) ? CellType::CORNER_BR : type;
    ctx.x = x+1;
    ctx.y = y+1;
    ctx.new_type = CellType::CORNER_BR_SINGLE;
    ctx.area_check = br_area;
    if (is_corner(ctx)) return true;


    return false;
}


void Maze::initMaze(Maze *maze){

    for (int y = 0; y < maze->height; y++) {

        maze->terrain[y] = new Cell[maze->width];

        for (int x = 0; x < maze->width; x++) {


            CellType type = CellType::EMPTY;
            if (corner_cases(maze,x,y,type)){
                setTerrain(x,y,type);
                continue;
            }

            if (wall_cases(maze,x,y,type)){
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


bool shouldDuplicate(CellType type) {

    switch (type) {

        case CellType::CORNER_TL:
        case CellType::CORNER_TR:
        case CellType::CORNER_BL:
        case CellType::CORNER_BR:
        case CellType::CORNER_TL_SINGLE:
        case CellType::CORNER_TR_SINGLE:
        case CellType::CORNER_BL_SINGLE:
        case CellType::CORNER_BR_SINGLE:
        case CellType::TEE_UP:
        case CellType::TEE_DOWN:
        case CellType::TEE_LEFT:
        case CellType::TEE_RIGHT:
        case CellType::CROSS:
        case CellType::LINE_UP:
        case CellType::LINE_DOWN:
        case CellType::LINE_LEFT:
        case CellType::LINE_RIGHT:
        case CellType::TEE_UP_SINGLE:
        case CellType::TEE_DOWN_SINGLE:
        case CellType::TEE_LEFT_SINGLE:
        case CellType::TEE_RIGHT_SINGLE:
        case CellType::CROSS_SINGLE:
        case CellType::PLAYER:
        case CellType::WALL_VERTICAL:
        case CellType::LINE_VERTICAL:
            return false;


        case CellType::EMPTY:
        case CellType::WALL_HORIZONTAL:
        case CellType::LINE_HORIZONTAL:
        default:
            return true;
    }
}

void buildString(PrintContext ctx, string &line) {
    string u = ctx.cell.getType(true);
    CellType ct = ctx.cell.getType();

    bool left_can_expend  = ctx.x % 2 == 0 && ctx.x < ctx.w / 2;
    bool right_can_expend = ctx.x % 2 == 1 && ctx.x > ctx.w / 2;


    if (!(left_can_expend || right_can_expend) && shouldDuplicate(ct)) {


        line.append(u + u + u + u);

    } else {
        line.append(u);
    }
}
void Maze::printTerrain(){

    for (int y = 0; y < height; y++) {

        string line = "";

        for (int x = 0; x < width; x++) {

            PrintContext ctx{
                x,
                y,
                width,
                height,
                terrain[y][x]

            };

            buildString(ctx, line);
        }

        cout << line << endl;
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
