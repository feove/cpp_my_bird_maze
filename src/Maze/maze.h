
#ifndef MAZE_H
#define MAZE_H

#include <cstddef>
#include <string>
#include <iostream>
#include <memory>
#include "cell.h"

using namespace std;

class Maze{

	private:
		int cx; //frontend purposes
		int cy;

		int x;
		int y;

		int width;
		int height;

		std::unique_ptr<Cell*[]> terrain;

	public:

	Maze(int _cx, int _cy, int x = 0, int y = 0, int width = 16, int height = 16);

	void initMaze(Maze *maze);

	~Maze();

	int getX();

	int getY();

	int getWidth();

	int getHeight();
	//void deinit(Maze *maze);

	void printBackend();

	void printTerrain();

	void setTerrain(int x, int y, CellType type);

};


#endif /* ! MAZE_H */
