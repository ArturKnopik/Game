#include "Arkanoid_SpeedUpBallBuff.h"
#include <iostream>
#include "Arkanoid_BuffFactory.h"
Arkanoid::Buffs::SpeedUpBallBuff::SpeedUpBallBuff(float duration, Arkanoid::Ball & ball)
	:Arkanoid::Buffs::IBuff(duration), ballPTR(&ball)
{
	goodEvilBuff = BuffType::EVIL_BUFF;
	buffTypee = Arkanoid::Buffs::Buff::SPEED_BALL;
	this->ballPTR->increaseSpeed();
	this->ballPTR->increaseSpeed();
	this->ballPTR->increaseSpeed();
}

void Arkanoid::Buffs::SpeedUpBallBuff::update(const float dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::SpeedUpBallBuff::~SpeedUpBallBuff()
{
	ballPTR->resetSpeed();
}
