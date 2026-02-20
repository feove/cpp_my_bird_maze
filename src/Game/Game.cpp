
#include "Game.h"
#include "../Maze/maze.h"

#include <iostream>

using namespace std;

void GameClass::run(GameClass *game){

	game->maze->setTerrain(game->maze, 0, 0, "W");	


	
	game->maze->setTerrain(game->maze, 5, 12, "W");
		
	cout << "Game Running ..." << endl;
}

GameClass::GameStatus GameClass::init(GameClass *game){

	cout << "Game Init" << endl;

	
	if (game->maze->init(game->maze)) return GameStatus::INIT_FAILURE;

	return GameStatus::INIT_SUCCESS;
}

void GameClass::deinit(GameClass *game){

	game->maze->deinit(game->maze);
	cout << "Game Deinit" << endl;
}


void Test::test(){


	std::cout << "Testing Only" << endl; 
}

