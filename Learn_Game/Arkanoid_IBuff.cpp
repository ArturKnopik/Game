#include "Arkanoid_IBuff.h"
#include <iostream>
void Arkanoid::Buffs::IBuff::removeLife(const double dt)
{
	currentDuration -= dt;
}

Arkanoid::Buffs::IBuff::IBuff(double duration)
	:currentDuration(duration), duration(duration), speed(0.0003)
{
}

sf::Vector2f Arkanoid::Buffs::IBuff::getPosition()
{
	return position;
}

bool Arkanoid::Buffs::IBuff::isBuffGood()
{
	if (goodEvilBuff == BuffType::GOOD_BUFF)
	{
		return true;
	}
	else if (goodEvilBuff == BuffType::EVIL_BUFF)
	{
		return false;
	}
}

double Arkanoid::Buffs::IBuff::getDuration()
{
	return duration;
}

double Arkanoid::Buffs::IBuff::getCurrentDuration()
{
	return currentDuration;
}

Arkanoid::Buffs::Buff Arkanoid::Buffs::IBuff::getBuffType()
{
	return buffTypee;
}
