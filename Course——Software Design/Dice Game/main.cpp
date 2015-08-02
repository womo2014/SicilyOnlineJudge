#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Game.h"
#include "Console.h"
using namespace std;

int main() {
	// initialize a game
	sndPlaySound("±≥æ∞“Ù¿÷.wav", SND_FILENAME|SND_LOOP|SND_ASYNC); // play background music 
	Game game; 
	game.start(); 
	while ( game.run());
	return 0;
}
