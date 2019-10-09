#include "Arkanoid_Ball.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>

void Arkanoid::Ball::updateBuffs(const double dt)
{
}

Arkanoid::Ball::Ball()
	:updateAble(false), radius(5), oryginalRadius(5), speed(0.0004f), currentSpeed(0.0004f), angle((3.1415926536 / 180) * 50), speedMultipler(1)
{
	position = sf::Vector2f(480, 600);
	speedValue.x += currentSpeed * sin(angle + 3.1459);
	speedValue.y += currentSpeed * cos(angle + 3.1459);
}

Arkanoid::Ball::Ball(sf::Vector2f position, double radius)
	:position(position), radius(radius), oryginalRadius(radius), speed(0.0004f), currentSpeed(0.0004f), angle((3.1415926536 / 180) * 50), speedMultipler(1)
{
	speedValue.x += currentSpeed * sin(angle + 3.1459);
	speedValue.y += currentSpeed * cos(angle + 3.1459);
}

void Arkanoid::Ball::update(const double dt)
{
	if (updateAble)
	{
		oldPosition = position;
		position.x += speedValue.x * dt*speedMultipler;
		position.y += speedValue.y * dt*speedMultipler;
	}
}

void Arkanoid::Ball::increaseSpeed()
{
	speedMultipler += 0.2;
}

void Arkanoid::Ball::decreaseSpeed()
{
	if(speedMultipler>0.3)
	speedMultipler -= 0.2;
}

void Arkanoid::Ball::resetSpeed()
{
	speedMultipler = 1;
}

const sf::Vector2f Arkanoid::Ball::getPosition() const
{
	return position;
}

const double Arkanoid::Ball::getRadius() const
{
	return radius;
}

void Arkanoid::Ball::changeSize(double radius)
{
	this->radius = radius;
}

void Arkanoid::Ball::resetRadius()
{
	radius = oryginalRadius;
}

void Arkanoid::Ball::setRadius(double radius)
{
	this->radius = radius;
}

void Arkanoid::Ball::setHitAngle(const Arkanoid::Paddle & paddle)
{
	double paddleCenter;
	paddleCenter = paddle.getPosition().x + paddle.getSize().x / 2;
	double distanceFromCenter = abs(paddleCenter -getPosition().x+getRadius() );
	if (getPosition().x + getRadius() < paddleCenter)
	{
		speedValue.x = currentSpeed * sin(1.05 * 100 / paddle.getSize().x *distanceFromCenter*3.1459 / 180 + 3.1459+ 0.261);
		speedValue.y = currentSpeed * cos(1.05 * 100 / paddle.getSize().x *distanceFromCenter*3.1459 / 180 + 3.1459+ 0.261);
	}
	else
	{
		speedValue.x = currentSpeed * sin((1.05 * 100 / paddle.getSize().x *distanceFromCenter*3.1459 / 180)*-1 + 3.1459- 0.261);
		speedValue.y = currentSpeed * cos((1.05 * 100 / paddle.getSize().x *distanceFromCenter*3.1459 / 180)*-1 + 3.1459- 0.261);
	}
}

void Arkanoid::Ball::reverseXSpeed()
{
	position = oldPosition;
	speedValue.x = speedValue.x*-1;
}

void Arkanoid::Ball::reverseYSpeed()
{
	position = oldPosition;
	speedValue.y = speedValue.y*-1;
}

const double Arkanoid::Ball::getAngle() const
{
	return 180*angle/3.14;
}

void Arkanoid::Ball::setPosition(sf::Vector2f pos)
{
	this->position = pos;
}

void Arkanoid::Ball::setUpdateAble(bool uA)
{
	updateAble = uA;
}

bool Arkanoid::Ball::getUpdateAble()
{
	return updateAble;
}