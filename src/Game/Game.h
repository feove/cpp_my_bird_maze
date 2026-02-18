#ifndef GAME_H
#define GAME_H

class GameClass{

	public: enum GameStatus {
		
		INIT_FAILURE,
		INIT_SUCCESS,
		RUNNING

	}; 
	
	public: GameStatus init();
	public: void deinit();
	public: void run();

};

class Test{

	public: void test();
	
};

#endif /* ! GAME_H */
