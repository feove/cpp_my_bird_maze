
#include "cell.h"
#include "maze_unicode.h"
#include <string>

CellType Cell::getType() const{
    return type;
}

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

void Cell::setPosition(int new_x, int new_y){
    x = new_x;
    y = new_y;
    return;
}

std::string Cell::getUnicode() const {
    switch (type) {
        case CellType::EMPTY:             return " ";
        case CellType::WALL_HORIZONTAL:   return "═";
        case CellType::WALL_VERTICAL:     return "║";
        case CellType::CORNER_TL:         return "╔";
        case CellType::CORNER_TR:         return "╗";
        case CellType::CORNER_BL:         return "╚";
        case CellType::CORNER_BR:         return "╝";
        case CellType::TEE_UP:            return "╩";
        case CellType::TEE_DOWN:          return "╦";
        case CellType::TEE_LEFT:          return "╣";
        case CellType::TEE_RIGHT:         return "╠";
        case CellType::CROSS:             return "╬";
        case CellType::LINE_UP:           return "╷";
        case CellType::LINE_DOWN:         return "╵";
        case CellType::LINE_LEFT:         return "╶";
        case CellType::LINE_RIGHT:        return "╴";
        case CellType::CORNER_LEFT_UP:    return "┘";
        case CellType::CORNER_RIGHT_UP:   return "└";
        case CellType::CORNER_LEFT_DOWN:  return "┐";
        case CellType::CORNER_RIGHT_DOWN: return "┌";
        case CellType::TEE_UP_SINGLE:     return "┴";
        case CellType::TEE_DOWN_SINGLE:   return "┬";
        case CellType::TEE_LEFT_SINGLE:   return "┤";
        case CellType::TEE_RIGHT_SINGLE:  return "├";
        case CellType::CROSS_SINGLE:      return "┼";
        case CellType::PLAYER:            return "🐦";
        default:                          return "?";
    }
}

bool Cell::operator==(const Cell& other) const {
    return x == other.x && y == other.y && type == other.type;
}
