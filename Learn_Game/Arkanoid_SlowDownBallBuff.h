#pragma once
#include "Arkanoid_Ball.h"
namespace Arkanoid
{
	namespace Buffs
	{
		class SlowDownBallBuff : public Arkanoid::Buffs::IBuff
		{
			Arkanoid::Ball * ballPTR;
		public:
			SlowDownBallBuff() = delete;
			SlowDownBallBuff(float duration, Arkanoid::Ball & ball);
			virtual void update(const float dt);
			~SlowDownBallBuff();
		};
	}
}

