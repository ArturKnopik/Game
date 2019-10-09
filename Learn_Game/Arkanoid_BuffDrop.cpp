#include "Arkanoid_BuffDrop.h"


Arkanoid::Buffs::BuffDropBall::BuffDropBall(sf::Vector2f position, Arkanoid::Buffs::WhatToBuff buffType)
	:position(position), buff(buffType)
{
	ball.setPosition(position);
	ball.setRadius(15);
}

void Arkanoid::Buffs::BuffDropBall::update(const double dt)
{

	position.y = position.y + 0.0003*dt;
	ball.setPosition(position);
}

sf::Vector2f Arkanoid::Buffs::BuffDropBall::getPosition()
{
	return position;
}

void Arkanoid::Buffs::BuffDropBall::setPosition(sf::Vector2f position)
{
	this->position = position;
}

const Arkanoid::Ball & Arkanoid::Buffs::BuffDropBall::getBall()
{
	return ball;
}

Arkanoid::Buffs::WhatToBuff Arkanoid::Buffs::BuffDropBall::getBuff()
{
	return buff;
}
