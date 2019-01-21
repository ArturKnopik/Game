#include "TicTacToc_Cell.h"


TicTacToc::Cell::Cell(char symbol, sf::Vector2f position, sf::Vector2f size)
	:symbol(symbol), position(position), size(size)
{
}

void TicTacToc::Cell::markCell(char symbol)
{
	this->symbol = symbol;
}

char TicTacToc::Cell::getSymbol()
{
	return symbol;
}

sf::Vector2f TicTacToc::Cell::getPosition()
{
	return position;
}

sf::Vector2f TicTacToc::Cell::getSize()
{
	return size;
}

