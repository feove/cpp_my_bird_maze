#include <iostream>
#include <string>

#include "maze.h"
#include "../Game/Game.h"

using namespace std;




int Maze::init(Maze *maze){

	std::cout << "--- Maze ---" << endl;

	string wall = "";
	string object = "";
	

	for (int j = 0; j < MAZE_SIZE/2; j++) {
		
		for (int i = 0; i < MAZE_SIZE; i++){

			string border =  (j == 0 || j == MAZE_SIZE - 1) ? "=" : "-";

			object = (i == 0) ? "[" : (i == MAZE_SIZE - 1) ? "]" : border;
			
				
			wall.append(object);
		}

		maze->terrain[j] = wall;

		wall = "";
	}	
    
	
	return 0;
}

void Maze::deinit(Maze *maze){

	cout << "Maze Deinit" << endl;
}

void Maze::setTerrain(Maze *maze, int x, int y, const string& item){

    int size = maze->terrain[x].length();
    
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < size) {

        maze->terrain[x].replace(y, item.length(), item);
        
    }else{
    
    	cout << "Out of Band from string\n";
    }
}


void Maze::printTerrain(Maze *maze){

//	cout << "Maze Terrain: " << endl;

	for (int i = 0; i < MAZE_SIZE; i++) {

		if ( maze->terrain[i] != ""){
			
		cout << maze->terrain[i] << "\n";
		}

	}

	cout << endl;
}
