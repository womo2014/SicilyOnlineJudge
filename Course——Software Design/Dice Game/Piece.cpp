#include "Piece.h"

void Piece::setPos(int pos)
{
	this->pos = pos;
}

const char* Piece::getIcon()
{
	return icon;
}

Piece::Piece(int att, const char *icon, int pos, int absCoordX, int absCoordY)
{
	this->icon = icon;
	attribute = att;
	this->pos = pos;
	absCoord.X = absCoordX;
	absCoord.Y = absCoordY;
}

int Piece::getPos()
{
	return pos;
}

WORD *Piece::getAttribute()
{
	return &attribute;
}

COORD Piece::getAbsCoord()
{
	return absCoord;
}
