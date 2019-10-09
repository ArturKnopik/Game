#pragma once

#include "Arkanoid_IBuff.h"
#include "Arkanoid_Ball.h"
#include "Arkanoid_BuffFactory.h"
namespace Arkanoid
{
	namespace Buffs
	{
		class SpeedUpBallBuff : public Arkanoid::Buffs::IBuff
		{
			Arkanoid::Ball * ballPTR;
		public:
			SpeedUpBallBuff() = delete;
			SpeedUpBallBuff(double duration, Arkanoid::Ball & ball);
			virtual void update(const double dt);
			~SpeedUpBallBuff();
		};
	}
}

