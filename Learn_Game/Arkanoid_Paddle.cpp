#include "Arkanoid_Paddle.h"



Arkanoid::Paddle::Paddle()
	:life(5)
{
	position = sf::Vector2f(100, 630);
	size = sf::Vector2f(100, 10);
}

Arkanoid::Paddle::~Paddle()
{
}

void Arkanoid::Paddle::removeLife()
{
	life--;
}

void Arkanoid::Paddle::addLife()
{
	life++;
}

const int Arkanoid::Paddle::getCurrentLife() const
{
	return life;
}

void Arkanoid::Paddle::draw(std::shared_ptr<sf::RenderWindow> window)
{
}

void Arkanoid::Paddle::moveLeft(const float dt)
{
	position.x=position.x-(0.0005f *dt);
}

void Arkanoid::Paddle::moveRight(const float dt)
{
	position.x = position.x + (0.0005f *dt);
}

void Arkanoid::Paddle::update(const float dt)
{
	if (dir == Direction::LEFT)
	{
		moveLeft(dt);
		dir = Direction::STOP;
	}
	else if (dir==Direction::RIGHT)
	{
		moveRight(dt);
		dir = Direction::STOP;
	}
	else
	{
		dir = Direction::STOP;
	}
}

void Arkanoid::Paddle::setDirection(Direction dir)
{
	this->dir = dir;
}

void Arkanoid::Paddle::input(std::shared_ptr<sf::Event> event)
{

	
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				setDirection(Arkanoid::Direction::LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				setDirection(Arkanoid::Direction::RIGHT);
			}
			else
			{
				setDirection(Arkanoid::Direction::STOP);
			}
		
			
			
}

void Arkanoid::Paddle::setPosition(sf::Vector2f pos)
{
	position = pos;
}

sf::Vector2f Arkanoid::Paddle::getSize() const
{
	return size;
}

sf::Vector2f Arkanoid::Paddle::getPosition() const
{
	return position;
}

void Arkanoid::Paddle::setSize(sf::Vector2f size)
{
	this->size = size;
}
