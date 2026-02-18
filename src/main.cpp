#include <iostream>

#include "Maze/maze.h"
#include "Game/Game.h"

using namespace std;


int main() {

	GameClass *game = new GameClass();

	
	
	game->maze = new Maze();
	
	Test test;
	
	
	if (game->init(game) == GameClass::INIT_FAILURE) {

		cout << "Game Init Failure" << endl;
		game->deinit(game);
		exit(1);
	}

	game->maze->printTerrain(game->maze);	

	//need loop
	game->run(game);	 


	game->maze->printTerrain(game->maze);	
	
	game->deinit(game);
	

    return 0;
}
