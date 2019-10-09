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
			SmallPaddleBuff(double duration, Arkanoid::Paddle & paddle);
			virtual void update(const double dt);
			~SmallPaddleBuff();
		};
	}
}

