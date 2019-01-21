#include "Arkanoid_Block.h"
#include <SFML/Graphics/RectangleShape.hpp>

Arkanoid::Block::Block(float x, float y, float width, float height, int life)
	:life(life)
{
	center.x = x + (width / 2);
	center.y = y + (height / 2);
	position = sf::Vector2f(x, y);
	size = sf::Vector2f(width, height);
	blockType = BlockType::DESTRUCTIBLE;
}

Arkanoid::Block::Block(sf::Vector2f position, sf::Vector2f size, int life)
	:position(position), size(size), life(life)
{
	center.x = position.x + (size.x / 2);
	center.y = position.y + (size.y / 2);
	blockType = BlockType::DESTRUCTIBLE;
}

void Arkanoid::Block::setSize(sf::Vector2f size)
{
	this->size = size;
}

void Arkanoid::Block::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void Arkanoid::Block::removeLife()
{
	if (blockType == BlockType::DESTRUCTIBLE)
	{
		life--;
	}
}

void Arkanoid::Block::update(const float dt)
{
}

const sf::Vector2f Arkanoid::Block::getCenter()
{
	return center;
}

int Arkanoid::Block::getCurrentLife()
{
	return life;
}

const sf::Vector2f Arkanoid::Block::getPosition()
{
	return position;
}

const sf::Vector2f Arkanoid::Block::getSize()
{
	return size;
}

Arkanoid::Block::~Block()
{
}

