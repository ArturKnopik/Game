#include "Arkanoid_IBuff.h"
#include <iostream>
void Arkanoid::Buffs::IBuff::removeLife(const float dt)
{
	currentDuration -= dt;
}

Arkanoid::Buffs::IBuff::IBuff(float duration)
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

float Arkanoid::Buffs::IBuff::getDuration()
{
	return duration;
}

float Arkanoid::Buffs::IBuff::getCurrentDuration()
{
	return currentDuration;
}

Arkanoid::Buffs::Buff Arkanoid::Buffs::IBuff::getBuffType()
{
	return buffTypee;
}
