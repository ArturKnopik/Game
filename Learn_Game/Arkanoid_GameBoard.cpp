#include "Arkanoid_GameBoard.h"

Arkanoid::GameBoard::GameBoard()
{
	position.x = 30;
	position.y = 30;
	size.x = 900;
	size.y = 630;
}

Arkanoid::GameBoard::GameBoard(float x, float y, float w, float h)
{
	position.x = x;
	position.y = y;
	size.x = w;
	size.y = h;
}

Arkanoid::GameBoard::GameBoard(sf::Vector2f position, sf::Vector2f size)
:position(position), size(size)
{
}

Arkanoid::GameBoard::~GameBoard()
{
}

const sf::Vector2f Arkanoid::GameBoard::getPosition()
{
	return position;
}

const sf::Vector2f Arkanoid::GameBoard::getSize()
{
	return size;
}
