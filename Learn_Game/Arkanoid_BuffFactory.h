#pragma once
#include "Arkanoid_Ball.h"
#include "Arkanoid_Paddle.h"
#include "Arkanoid_PointSystem.h"
#include "Arkanoid_BuffSystem.h"
#include "Arkanoid_BuffDrop.h"
#include "Arkanoid_SpeedUpBallBuff.h"
#include "Arkanoid_SlowDownBallBuff.h"
#include "Arkanoid_BigPaddleBuff.h"
#include "Arkanoid_SmallPaddleBuff.h"
#include "Arkanoid_AddPointBuff.h"
#include "Arkanoid_PointMultiplerBuff.h"
#include <iostream>
namespace Arkanoid
{
	namespace Buffs
	{
		class BuffFactory
		{
		public:
			BuffFactory() = default;
			~BuffFactory() = default;
			std::shared_ptr<Arkanoid::Buffs::IBuff> getNewBuff(Arkanoid::Ball & ball);
			std::shared_ptr<Arkanoid::Buffs::IBuff> getNewBuff(Arkanoid::Paddle & paddle);
			std::shared_ptr<Arkanoid::Buffs::IBuff> getNewbuff(Arkanoid::PointSystem & pointSytem);
		};
	}
}
