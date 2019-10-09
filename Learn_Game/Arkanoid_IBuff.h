#pragma once
#include <SFML/System/Vector2.hpp>
namespace Arkanoid
{
	namespace Buffs
	{
		enum BuffType
		{
			GOOD_BUFF,
			EVIL_BUFF
		};
		enum Buff
		{
			SPEED_BALL = 1,
			SLOW_BALL = 2,
			BIG_PADDLE = 3,
			SMALL_PADDLE = 4,
			POINT_BUFF_MULTIPLER = 5,
			POINT_BUFF_POINTS = 6
		};

		class IBuff
		{
			

			double currentDuration;
			double duration;
			double speed;
		protected:
			Buff buffTypee;
			BuffType goodEvilBuff;
			void removeLife(const double dt);
			sf::Vector2f position;
		public:
			IBuff(double duration);
			virtual ~IBuff() = default;
			virtual void update(const double dt) = 0;
			sf::Vector2f getPosition();
			bool isBuffGood();
			double getDuration();
			double getCurrentDuration();
			Arkanoid::Buffs::Buff getBuffType();
		};
	}
}


