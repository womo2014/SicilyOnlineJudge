#include "Player.h"
#include "Console.h"
#include "GameInterface.h"

#ifndef _GAME_H_
#define _GAME_H_
class Game {
public:
	Game();
	~Game();
	void start();
	void initialEvents(int *&events); 
	const char* getEvent();
	bool run(); // run a round and return flase if game overs

private:
	void setEvent(int *events, bool setted[], int n, int value); // set the value of every n events to value
	int *events[2];
	Player *player[2]; // pointers point to players
	const char *eventMess[6];
	GameInterface gameInterface;
	int _n; // the size of the board
	bool turn; // turn = 0 for A and trun = 1 for B
	int round; // count number of game's round
};
#endif 
