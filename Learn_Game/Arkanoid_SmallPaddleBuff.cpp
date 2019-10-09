#include "Arkanoid_SmallPaddleBuff.h"
#include "Arkanoid_BuffFactory.h"
Arkanoid::Buffs::SmallPaddleBuff::SmallPaddleBuff(double duration, Arkanoid::Paddle & paddle)
	:Arkanoid::Buffs::IBuff(duration), paddlePTR(&paddle)
{
	goodEvilBuff = BuffType::EVIL_BUFF;
	buffTypee = Arkanoid::Buffs::Buff::SMALL_PADDLE;
	paddlePTR->setSize(sf::Vector2f(paddlePTR->getSize().x / 2, paddlePTR->getSize().y));
}

void Arkanoid::Buffs::SmallPaddleBuff::update(const double dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::SmallPaddleBuff::~SmallPaddleBuff()
{
	paddlePTR->setSize(sf::Vector2f(paddlePTR->getSize().x * 2, paddlePTR->getSize().y));
}
