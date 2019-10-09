#pragma once
#include "Arkanoid_IBuff.h"
#include "Arkanoid_PointSystem.h"
namespace Arkanoid
{
	namespace Buffs
	{
		class AddPointBuff : public Arkanoid::Buffs::IBuff
		{
			Arkanoid::PointSystem * pointSystem;
		public:
			AddPointBuff(Arkanoid::PointSystem & pointSystem, int pointsToAdd);
			virtual void update(const double dt);
			~AddPointBuff();
		};
	}
}
