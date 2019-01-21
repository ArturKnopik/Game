#include "Arkanoid_PointSystem.h"

Arkanoid::PointSystem::PointSystem()
	:points(0), pointPerHit(10), basicPointMultipler(1), maxPointMultipler(10), buffedMultipler(1)
{
}

Arkanoid::PointSystem::PointSystem(int pointPerHit, int maxPointMultipler)
	: points(0), pointPerHit(pointPerHit), basicPointMultipler(1), maxPointMultipler(maxPointMultipler), buffedMultipler(1)
{
}

void Arkanoid::PointSystem::increaseBasicMultipler()
{
	if (basicPointMultipler < 10)
	{
		basicPointMultipler++;
	}
}

void Arkanoid::PointSystem::increaseBuffMultipler(int multiplier)
{
	buffedMultipler = multiplier;
}

void Arkanoid::PointSystem::resetBasicMultipler()
{
	basicPointMultipler = 1;
}

void Arkanoid::PointSystem::resetBuffMultipler()
{
	buffedMultipler = 1;
}

void Arkanoid::PointSystem::addPoints(int points)
{
	this->points = this->points + (points*basicPointMultipler*buffedMultipler);
}

void Arkanoid::PointSystem::reset()
{
	points = 0;
	basicPointMultipler = 1;
	buffedMultipler = 1;
}

int Arkanoid::PointSystem::getPoints()
{
	return points;
}

int Arkanoid::PointSystem::getBasicMultipler()
{
	return basicPointMultipler;
}

int Arkanoid::PointSystem::getBuffMultipler()
{
	return buffedMultipler;
}
