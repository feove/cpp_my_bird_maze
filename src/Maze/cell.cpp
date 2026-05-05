
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
        case CellType::EMPTY:             return unicode ? " " : " E ";
        case CellType::WALL_HORIZONTAL:   return  unicode ? "═" : "W_H";
        case CellType::WALL_VERTICAL:     return  unicode ? "║" : "W_V";
        case CellType::CORNER_TL:         return unicode ? "╔" : "CTL";
        case CellType::CORNER_TR:         return unicode ? "╗" : "CTR";
        case CellType::CORNER_BL:         return unicode ? "╚" : "CBL";
        case CellType::CORNER_BR:         return unicode ? "╝" : "CBB";
        case CellType::TEE_UP:            return unicode ? "╩" : "T_U";
        case CellType::TEE_DOWN:          return unicode ? "╦" : "T_D";
        case CellType::TEE_LEFT:          return unicode ? "╣" : "T_L";
        case CellType::TEE_RIGHT:         return unicode ? "╠" : "T_R";
        case CellType::CROSS:             return unicode ? "╬" : " X ";
        case CellType::LINE_UP:           return unicode ? "╷" : "L_U";
        case CellType::LINE_DOWN:         return unicode ? "╵" : "L_D";
        case CellType::LINE_LEFT:         return unicode ? "╶" : "L_L";
        case CellType::LINE_RIGHT:        return unicode ? "╴" : "L_R";
        case CellType::CORNER_BR_SINGLE:    return unicode ? "┘" : "CLU";
        case CellType::CORNER_BL_SINGLE:   return unicode ? "└" : "CRU";
        case CellType::CORNER_TR_SINGLE:  return unicode ? "┐" : "CLD";
        case CellType::CORNER_TL_SINGLE: return unicode ? "┌" : "CRD";
        case CellType::TEE_UP_SINGLE:     return unicode ? "┴" : "TUS";
        case CellType::TEE_DOWN_SINGLE:   return unicode ? "┬" : "TDS";
        case CellType::TEE_LEFT_SINGLE:   return unicode ? "┤" : "TLS";
        case CellType::TEE_RIGHT_SINGLE:  return unicode ? "├" : "TRS";
        case CellType::CROSS_SINGLE:      return unicode ? "┼" : "C_S";
        case CellType::PLAYER:            return unicode ? "🐦" : " P ";
        default:                          return "?";
    }
}

bool Cell::operator==(const Cell& other) const {
    return x == other.x && y == other.y && type == other.type;
}
