#include "Arkanoid_BigPaddleBuff.h"
#include "Arkanoid_BuffFactory.h"

Arkanoid::Buffs::BigPaddleBuff::BigPaddleBuff(double duration, Arkanoid::Paddle & paddle)
	:Arkanoid::Buffs::IBuff(duration), paddlePTR(&paddle)
{
	goodEvilBuff = Arkanoid::Buffs::BuffType::GOOD_BUFF;
	buffTypee = Arkanoid::Buffs::Buff::BIG_PADDLE;
	paddlePTR->setSize(sf::Vector2f(paddlePTR->getSize().x * 2, paddlePTR->getSize().y));
	paddlePTR->setPosition(sf::Vector2f(paddlePTR->getPosition().x - paddlePTR->getSize().x / 4, paddlePTR->getPosition().y));
}

void Arkanoid::Buffs::BigPaddleBuff::update(const double dt)
{
	removeLife(dt);
}

Arkanoid::Buffs::BigPaddleBuff::~BigPaddleBuff()
{
	paddlePTR->setPosition(sf::Vector2f(paddlePTR->getPosition().x + paddlePTR->getSize().x / 4, paddlePTR->getPosition().y));
	paddlePTR->setSize(sf::Vector2f(paddlePTR->getSize().x / 2, paddlePTR->getSize().y));
}
