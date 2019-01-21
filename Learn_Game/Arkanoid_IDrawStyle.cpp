#include "Arkanoid_IDrawStyle.h"
#include "Arkanoid_Block.h"
#include <iostream>


void Arkanoid::IDrawStyle::setPlayingRect(Arkanoid::GameBoard & gameBoard)
{
	playingField = gameBoard;
}

