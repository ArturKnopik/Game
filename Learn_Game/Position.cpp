#include "Position.h"



kr::Position::Position()
{
}

kr::Position::Position(float x, float y)
	: x(x), y(y)
{
}

const float kr::Position::getX()
{
	return x;
}

const float kr::Position::getY()
{
	return y;
}

void kr::Position::setX(const float x)
{
	this->x = x;
}

void kr::Position::setY(const float y)
{
	this->y = y;
}


kr::Position::~Position()
{
}
