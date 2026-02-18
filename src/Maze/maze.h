
#ifndef MAZE_H
#define MAZE_H

#include <cstddef>

class Maze{	

	//public: Maze *maze;

	public: 
	
	static const int MAZE_SIZE = 32;  

	int terrain[MAZE_SIZE];  
    
	int init(Maze *maze);

	void deinit(Maze *maze);

	void printTerrain(Maze *maze);

	void setTerrain(Maze *maze, int x, int y, int value);
	
};


#endif /* ! MAZE_H */
