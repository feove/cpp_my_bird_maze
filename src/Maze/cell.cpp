
#include "cell.h"
#include "maze_unicode.h"
#include <string>


Cell::Cell() : x(0), y(0), type(CellType::EMPTY)
{}

Cell::Cell(int _x, int _y, CellType _type) : x(_x), y(_y), type(_type)
{}


int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}

void Cell::setType(CellType newType){
    type = newType;
    return;
}

CellType Cell::getType() const{
    return type;
}

void Cell::setPosition(int new_x, int new_y){
    x = new_x;
    y = new_y;
    return;
}

std::string Cell::getType(bool unicode) const {
    switch (type) {
        case CellType::EMPTY:             return unicode ? " " : "E";
        case CellType::WALL_HORIZONTAL:   return  unicode ? "═" : "WH";
        case CellType::WALL_VERTICAL:     return  unicode ? "║" : "WV";
        case CellType::CORNER_TL:         return unicode ? "╔" : "CT";
        case CellType::CORNER_TR:         return unicode ? "╗" : "CTR";
        case CellType::CORNER_BL:         return unicode ? "╚" : "CBL";
        case CellType::CORNER_BR:         return unicode ? "╝" : "CBB";
        case CellType::TEE_UP:            return unicode ? "╩" : "TU";
        case CellType::TEE_DOWN:          return unicode ? "╦" : "TD";
        case CellType::TEE_LEFT:          return unicode ? "╣" : "TL";
        case CellType::TEE_RIGHT:         return unicode ? "╠" : "TR";
        case CellType::CROSS:             return unicode ? "╬" : "X";
        case CellType::LINE_UP:           return unicode ? "╷" : "LU";
        case CellType::LINE_DOWN:         return unicode ? "╵" : "LD";
        case CellType::LINE_LEFT:         return unicode ? "╶" : "LL";
        case CellType::LINE_RIGHT:        return unicode ? "╴" : "LR";
        case CellType::CORNER_LEFT_UP:    return unicode ? "┘" : "CLU";
        case CellType::CORNER_RIGHT_UP:   return unicode ? "└" : "CRU";
        case CellType::CORNER_LEFT_DOWN:  return unicode ? "┐" : "CLD";
        case CellType::CORNER_RIGHT_DOWN: return unicode ? "┌" : "CRD";
        case CellType::TEE_UP_SINGLE:     return unicode ? "┴" : "TUS";
        case CellType::TEE_DOWN_SINGLE:   return unicode ? "┬" : "TDS";
        case CellType::TEE_LEFT_SINGLE:   return unicode ? "┤" : "TLS";
        case CellType::TEE_RIGHT_SINGLE:  return unicode ? "├" : "TRS";
        case CellType::CROSS_SINGLE:      return unicode ? "┼" : "CS";
        case CellType::PLAYER:            return unicode ? "🐦" : "P";
        default:                          return "?";
    }
}

bool Cell::operator==(const Cell& other) const {
    return x == other.x && y == other.y && type == other.type;
}
