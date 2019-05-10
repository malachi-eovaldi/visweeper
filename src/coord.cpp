#include "coord.h"

Coordinate::Coordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Coordinate::getx()
{
	return x;
}

int Coordinate::gety()
{
	return y;
}

void Coordinate::setx(int x)
{
	this->x = x;
}

void Coordinate::sety(int y)
{
	this->y = y;
}
