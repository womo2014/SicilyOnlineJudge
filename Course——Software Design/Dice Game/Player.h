#include <string>
#include "Dice.h"
#include "Piece.h"
using namespace std;

#ifndef _PLAYER_H_
#define _PLAYER_H_
class Player {
public:
	Player(const char *name, int *events, int numOfSmartDice); // specify the name, DiceMode = 1 for InputDice, 2 for RandomDice
	~Player();
	const char *getName();
	int getNumOfSmartDice();
	int useSmartDice(); 
	void gainPiece(WORD att, const char *icon, int pos, int absCoordX, int absCoordY); // to gain a piece with some attribute
	Piece &getPiece();
	virtual int play() = 0; 
protected:
	int *events; // to record the events list
	RandomDice randomDice; 
private:
	int numOfSmartDice; // the number of smart dice
	const char *name; // the name of the player
	Piece *piece; // the player's position on the board
};

class HumanPlayer: public Player
{
public:
	HumanPlayer(const char *name, int *events, int smartDiceNum);
	int play();
private:
	InputDice inputDice;
};

class ComputorPlayer: public Player
{
public:
	ComputorPlayer(const char *name, int *events, int numOfSmartDice, int mapSize, int difficuluty);
	int play();
private:
	int mapSize;
	int difficulty;
};

#endif 
