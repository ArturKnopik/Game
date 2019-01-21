#include "Arkanoid_Level.h"


void Arkanoid::Level::addBlock(std::shared_ptr<Arkanoid::Block> block)
{
	blockList.push_back(block);
}

Arkanoid::Level::Level()
{
	blockList.clear();
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			addBlock(std::shared_ptr<Block>(new Block(sf::Vector2f(40+j*100, 50+i*40), sf::Vector2f(90, 30), 2)));
		}
	}	
}

std::shared_ptr<Arkanoid::Level> Arkanoid::Level::getNextLevel()
{
	return std::shared_ptr<Arkanoid::Level>(new Arkanoid::Level());
}

std::vector<std::shared_ptr<Arkanoid::Block>> Arkanoid::Level::getBlockList()
{
	return blockList;
}

