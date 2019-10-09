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
			PointMultiplerBuff(double duration, Arkanoid::PointSystem & pointSystem, int pointsMultipler);
			virtual void update(const double dt);
			~PointMultiplerBuff();
		};
	}
}

