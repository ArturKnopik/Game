#pragma once
#include "Arkanoid_IBuff.h"
#include "Arkanoid_Paddle.h"
namespace Arkanoid
{
	namespace Buffs
	{
		class SmallPaddleBuff : public Arkanoid::Buffs::IBuff
		{
			Arkanoid::Paddle * paddlePTR;
		public:
			SmallPaddleBuff() = delete;
			SmallPaddleBuff(float duration, Arkanoid::Paddle & paddle);
			virtual void update(const float dt);
			~SmallPaddleBuff();
		};
	}
}

