#include <iostream>

#include "maze.h"
#include "../Game/Game.h"

using namespace std;
 
int Maze::init(Maze *maze){

	std::cout << "Maze Init" << endl;

	for (int i = 0; i < MAZE_SIZE; i++) {

		maze->terrain[i] = 2;
	}	
    
	
	return 0;
}

void Maze::deinit(Maze *maze){

	cout << "Maze Deinit" << endl;
}

void Maze::setTerrain(Maze *maze, int x, int y, int value){

	
	maze->terrain[x] = value;
		

}
	

void Maze::printTerrain(Maze *maze){

	cout << "Maze Terrain: " << endl;

	for (int i = 0; i < MAZE_SIZE; i++) {

		cout << maze->terrain[i] << " ";

	}

	cout << endl;
}
