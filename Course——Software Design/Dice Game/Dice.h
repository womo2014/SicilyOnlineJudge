#ifndef _DICE_H_
#define _DICE_H_
class Dice {
public:
	virtual int roll() = 0; // roll the dice to get a dice number
	
private:
};

class InputDice: public Dice
{
public:
	int roll();// get a dice number from stdin at a range from 1 to 6 
	
private:
};

class RandomDice: public Dice
{
public:
	int roll();// get a dice number from random function
private:		
};
#endif 
