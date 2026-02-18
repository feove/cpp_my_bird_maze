#include <iostream>

#include "Maze/maze.h"
#include "Game/Game.h"

using namespace std;


int main() {

	GameClass game;
	Maze maze;
	Test test;
	

	if (game.init() == GameClass::INIT_FAILURE) {

		cout << "Game Init Failure" << endl;
		game.deinit();
		exit(1);
	}
	
	//loop
	game.run();	 


	game.deinit();


//	test.test();

//    std::cout << "Hello World\n";

    return 0;
}
