#include "Player.h"
#include <algorithm>
using namespace std;
// class Play
Player::Player(const char* name, int *events, int numOfSmartDice)
{
	this->events = events;
	this->name = name;
	this->numOfSmartDice = numOfSmartDice;
}
int Player::useSmartDice()
{
	int diceNum = randomDice.roll();
	if ( numOfSmartDice != 0 ) {
		--numOfSmartDice;
		int i = -1;
		int count = 0;
		while (count < diceNum)
		{
			i = (i+1)%6;
			if (events[piece->getPos()+1+i] >= 0)
				++count; 
		}
		diceNum = i+1;
	}
	return diceNum;
}

void Player::gainPiece(WORD att, const char *icon, int pos, int absCoordX, int absCoordY)
{
	piece = new Piece(att, icon, pos, absCoordX, absCoordY);
}

const char* Player::getName()
{
	return name;
}

Piece &Player::getPiece()
{
	return *piece;
}
int Player::getNumOfSmartDice()
{
	return numOfSmartDice;
}
Player::~Player()
{
	delete piece;
}

// class HumanPlay
HumanPlayer::HumanPlayer(const char *name, int *events, int numOfSmartDice): Player(name, events, numOfSmartDice)
{
}

int HumanPlayer::play()
{
	int diceNum = inputDice.roll();
	if ( diceNum == 0) {
		diceNum = useSmartDice();
	}
	return diceNum;
}

// class ComputerPlay
ComputorPlayer::ComputorPlayer(const char *name, int *events, int numOfSmartDice, int mapSize, int difficulty): Player(name, events, numOfSmartDice)
{
	this->mapSize = mapSize;
	this->difficulty = difficulty;
}

int ComputorPlayer::play()
{
	if ( mapSize-this->getPiece().getPos() <= 6)
		return 6;
	int diceNum[difficulty];
	for ( int i = 0; i < difficulty; i++)
		diceNum[i] = randomDice.roll();
	for(int i = 0; i < difficulty; i++)
		for (int j = i+1; j < difficulty; j++)
			if ( events[getPiece().getPos()+diceNum[i]] < events[getPiece().getPos()+diceNum[j]]) {
				int t= diceNum[i];
				diceNum[i] = diceNum[j];
				diceNum[j] = t;
			}	
	if (events[getPiece().getPos()+diceNum[0]] < 0)
		return useSmartDice();
	else return diceNum[0];
}
