#include <iostream>

#include "Maze/maze.h"
#include "Game/Game.h"

using namespace std;


int main(void) {

	GameClass *game = new GameClass();

	game->maze = new Maze(0,0);

	Test test;

	if (game->init(game) == GameClass::INIT_FAILURE) {

		cout << "Game Init Failure" << endl;

		exit(1);
	}

	//need loop
	game->run(game);


	game->maze->printTerrain();

	game->maze->printBackend();

    return 0;
}
