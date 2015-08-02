#include "Console.h"

#ifndef _PIECE_H_
#define _PIECE_H_
class Piece 
{
public:
	Piece(int att, const char *icon, int pos, int absCoordX, int absCoordY);
	void setPos(int pos);
	WORD *getAttribute();
	int getPos();
	const char *getIcon();
	COORD getAbsCoord();
private:
	COORD absCoord;
	const char *icon;
	WORD attribute;
	int pos;
};
#endif
