#ifndef CELL_H
#define CELL_H

#include <string>

enum class CellType {
    EMPTY,
    WALL_HORIZONTAL,
    WALL_VERTICAL,
    CORNER_TL,
    CORNER_TR,
    CORNER_BL,
    CORNER_BR,
    TEE_UP,
    TEE_DOWN,
    TEE_LEFT,
    TEE_RIGHT,
    CROSS,
    LINE_UP,
    LINE_DOWN,
    LINE_LEFT,
    LINE_RIGHT,
    CORNER_LEFT_UP,
    CORNER_RIGHT_UP,
    CORNER_LEFT_DOWN,
    CORNER_RIGHT_DOWN,
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

    int getX() const;
    int getY() const;

    void setType(CellType newType);
    void setPosition(int newX, int newY);


    std::string getUnicode() const;

    bool operator==(const Cell& other) const;
};

#endif /* CELL_H */
