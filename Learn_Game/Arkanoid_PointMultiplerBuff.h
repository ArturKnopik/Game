#pragma once
#include "Arkanoid_IBuff.h"
#include "Arkanoid_PointSystem.h"
namespace Arkanoid
{
	namespace Buffs
	{
		class PointMultiplerBuff :public Arkanoid::Buffs::IBuff
		{
			Arkanoid::PointSystem * pointSystem;
		public:
			PointMultiplerBuff() = delete;
			PointMultiplerBuff(float duration, Arkanoid::PointSystem & pointSystem, int pointsMultipler);
			virtual void update(const float dt);
			~PointMultiplerBuff();
		};
	}
}

