#ifndef CELL_H
#define CELL_H

#include <string>

enum class CellType {
    EMPTY,
    DOOR,
    WALL_HORIZONTAL,
    WALL_VERTICAL,
    CORNER_TL, //4
    CORNER_TR,
    CORNER_BL,
    CORNER_BR, //7
    TEE_UP,
    TEE_DOWN,
    TEE_LEFT,
    TEE_RIGHT,
    CROSS,
    LINE_VERTICAL,
    LINE_HORIZONTAL,
    LINE_UP,
    LINE_DOWN,
    LINE_LEFT,
    LINE_RIGHT,
    CORNER_BL_SINGLE, //19
    CORNER_BR_SINGLE,
    CORNER_TL_SINGLE,
    CORNER_TR_SINGLE, //22
    TEE_UP_SINGLE,
    TEE_DOWN_SINGLE,
    TEE_LEFT_SINGLE,
    TEE_RIGHT_SINGLE,
    CROSS_SINGLE,
    PLAYER
};

class Cell {

    private:
        CellType type;
        int x;
        int y;

    public:

    Cell();

    Cell(int _x, int _y, CellType _type);

    CellType getType() const;

    std::string getType(bool unicode) const;

    int getX() const;
    int getY() const;

    void setType(CellType newType);
    void setPosition(int newX, int newY);


    bool operator==(const Cell& other) const;
};

#endif /* CELL_H */
