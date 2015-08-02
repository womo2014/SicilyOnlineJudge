#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Dice.h"
using namespace std;

int InputDice::roll()
{
	int diceNum;
	while (true) {	
		cout << "输入骰子点数：";
		cin >> diceNum;
		if ( diceNum >= 1 && diceNum <= 6 )
			return diceNum;
		else
			return 0; 
	}
}

int RandomDice::roll()
{
	int diceNum;
	srand((unsigned)time(NULL));
	diceNum = (rand() % 6) + 1;
	return diceNum;
}
