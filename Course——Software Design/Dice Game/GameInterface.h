#include "Console.h"
#include "Piece.h"
#include "Player.h"
#ifndef _GAMEINTERFACE_H_
#define _GAMEINTERFACE_H_
class GameInterface
{
public:
	GameInterface();
	~GameInterface();
	void welcomePage();
	int selectModePage(); // return 1 for "单人模式" and 2 for "双人模式"
	int selectDifficultyPage(); // return the difficulty of ComputerPlayer
	int inputSizePage(); // return the size of the map to generate
	void endPage();
	void introductionPage();
	void runGamePage(Piece& piece1, Piece& piece2); // draw a map and display piece1 and piece2 in the map
	void movePiece(Piece &piece, int dist); // move piece from current postion by a distance
	// reflash the infomation of two players and the round infomation
	void refreshInfoBox(Player *player1, Player *player2, const int round); 
	// display a message generated by the player on the infoBox
	void displayMess(Player *player, const char *mess); 
private:
	const char* str(int num);// convert a num to a string
	SMALL_RECT infoBox; // represent the size and position of the infomation box
	int mapSize; // the size of the map
	COORD *gridsCoord; // to record the map's every grid's coordinate on the window
	Console myConsole; 
};
#endif 
