
#include "Game.h"
#include "../Maze/maze.h"

#include <iostream>

using namespace std;

void GameClass::run(){

	cout << "Game Running ..." << endl;
}

GameClass::GameStatus GameClass::init(){

	cout << "Game Init" << endl;

	GameClass game;
	Maze maze;
	
	if (maze.init()) return GameStatus::INIT_FAILURE;

	return GameStatus::INIT_SUCCESS;
}

void GameClass::deinit(){

	cout << "Game Deinit" << endl;
}


void Test::test(){


	std::cout << "Testing Only" << endl; 
}

