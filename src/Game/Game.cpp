
#include "Game.h"
#include "../Maze/maze.h"

#include <iostream>

using namespace std;

void GameClass::run(GameClass *game){

	cout << "Game Running ..." << endl;
}

GameClass::GameStatus GameClass::init(GameClass *game){

	cout << "Game Init" << endl;


//	if (game->maze->init(game->maze)) return GameStatus::INIT_FAILURE;

	return GameStatus::INIT_SUCCESS;
}




void Test::test(){


	std::cout << "Testing Only" << endl;
}
