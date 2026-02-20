
#ifndef MAZE_H
#define MAZE_H

#include <cstddef>
#include <string>

class Maze{	

	public: 
	
	static const int MAZE_SIZE = 32;  

	std::string terrain[MAZE_SIZE];
    
	int init(Maze *maze);

	void deinit(Maze *maze);

	void printTerrain(Maze *maze);

	void setTerrain(Maze *maze, int x, int y, const std::string& item);
	
};


#endif /* ! MAZE_H */
