#ifndef GAME_H
#define GAME_H

#include "../Maze/maze.h"

class GameClass{

	private:
	
	public: 
	
	Maze *maze;
	
	enum GameStatus {
		
		INIT_FAILURE,
		INIT_SUCCESS,
		RUNNING

	}; 
	
 
	GameStatus init(GameClass *game);

	void deinit(GameClass *game);

	void run(GameClass *game);

};

class Test{

	public: void test();
	
};

#endif /* ! GAME_H */
