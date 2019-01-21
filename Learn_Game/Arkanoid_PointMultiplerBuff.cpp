#include "Arkanoid_PointMultiplerBuff.h"
#include "Arkanoid_BuffFactory.h"
Arkanoid::Buffs::PointMultiplerBuff::PointMultiplerBuff(float duration, Arkanoid::PointSystem & pointSystem, int pointsMultipler)
	:Arkanoid::Buffs::IBuff(duration), pointSystem(&pointSystem)
{
	goodEvilBuff = Arkanoid::Buffs::BuffType::GOOD_BUFF;
	buffTypee = Arkanoid::Buffs::Buff::POINT_BUFF_MULTIPLER;
	this->pointSystem->increaseBuffMultipler(pointsMultipler);
}

void Arkanoid::Buffs::PointMultiplerBuff::update(const float dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::PointMultiplerBuff::~PointMultiplerBuff()
{
	pointSystem->resetBuffMultipler();
}
