#include "Arkanoid_BuffFactory.h"

std::shared_ptr<Arkanoid::Buffs::IBuff> Arkanoid::Buffs::BuffFactory::getNewBuff(Arkanoid::Ball & ball)
{
	switch (rand()%2+1)
	{
	case 1:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::SpeedUpBallBuff(25000000, ball));
		break;
	case 2:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::SlowDownBallBuff(25000000, ball));
		break;
	default:
		return nullptr;
		break;
	}
}

std::shared_ptr<Arkanoid::Buffs::IBuff> Arkanoid::Buffs::BuffFactory::getNewBuff(Arkanoid::Paddle & paddle)
{
	switch (rand() % 2 + 1)
	{
	case 1:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::BigPaddleBuff(25000000, paddle));

		break;
	case 2:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::SmallPaddleBuff(25000000, paddle));
		break;
	default:
		return nullptr;
		break;
	}
}

std::shared_ptr<Arkanoid::Buffs::IBuff> Arkanoid::Buffs::BuffFactory::getNewbuff(Arkanoid::PointSystem & pointSytem)
{
	switch (rand() % 2 + 1)
	{
	case 1:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::AddPointBuff( pointSytem, rand()%15));

		break;
	case 2:
		return std::shared_ptr<IBuff>(new Arkanoid::Buffs::PointMultiplerBuff(25000000, pointSytem, rand() % 6+2));


		break;
	default:
		return nullptr;
		break;
	}

}


