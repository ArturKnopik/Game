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
			SpeedUpBallBuff(float duration, Arkanoid::Ball & ball);
			virtual void update(const float dt);
			~SpeedUpBallBuff();
		};
	}
}

