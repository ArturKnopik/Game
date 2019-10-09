#include "Arkanoid_AddPointBuff.h"
#include "Arkanoid_BuffFactory.h"

Arkanoid::Buffs::AddPointBuff::AddPointBuff(Arkanoid::PointSystem & pointSystem, int pointsToAdd)
	:Arkanoid::Buffs::IBuff(-10), pointSystem(&pointSystem)
{
	buffTypee = Arkanoid::Buffs::Buff::POINT_BUFF_POINTS;
	goodEvilBuff = Arkanoid::Buffs::BuffType::GOOD_BUFF;
	this->pointSystem->addPoints(pointsToAdd);
}

void Arkanoid::Buffs::AddPointBuff::update(const double dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::AddPointBuff::~AddPointBuff()
{
}
