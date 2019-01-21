#include "Arkanoid_SlowDownBallBuff.h"
#include "Arkanoid_BuffFactory.h"
Arkanoid::Buffs::SlowDownBallBuff::SlowDownBallBuff(float duration, Arkanoid::Ball & ball)
	:Arkanoid::Buffs::IBuff(duration), ballPTR(&ball)
{
	goodEvilBuff = BuffType::GOOD_BUFF;
	buffTypee = Arkanoid::Buffs::Buff::SLOW_BALL;
	this->ballPTR->decreaseSpeed();
	this->ballPTR->decreaseSpeed();
}

void Arkanoid::Buffs::SlowDownBallBuff::update(const float dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::SlowDownBallBuff::~SlowDownBallBuff()
{
	ballPTR->resetSpeed();
}
