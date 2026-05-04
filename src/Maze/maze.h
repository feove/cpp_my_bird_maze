
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

		int width;
		int height;

		std::unique_ptr<Cell*[]> terrain;

	public:

	Maze(int _cx, int _cy, int width = 32, int height = 16);

	~Maze();

	void deinit(Maze *maze);

	void printTerrain(Maze *maze);

	void setTerrain(Maze *maze, int x, int y, const std::string& item);

};


#endif /* ! MAZE_H */
