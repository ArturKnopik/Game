#pragma once
#include <SFML/System/Vector2.hpp>
#include "Arkanoid_IBuff.h"
#include "Arkanoid_BuffSystem.h"
#include "Arkanoid_Ball.h"
#include "Arkanoid_BuffFactory.h"
namespace Arkanoid
{
	namespace Buffs
	{
		enum  WhatToBuff
		{
			PADDLE = 1,
			BALL = 2,
			POINTS = 3
		};
		class BuffDropBall
		{
			Arkanoid::Ball ball;
			sf::Vector2f position;
			Arkanoid::Buffs::WhatToBuff buff;
		public:
			BuffDropBall() = delete;
			BuffDropBall(sf::Vector2f position, Arkanoid::Buffs::WhatToBuff buffType);
			void update(const double dt);
			sf::Vector2f getPosition();
			void setPosition(sf::Vector2f position);
			~BuffDropBall() = default;
			const Arkanoid::Ball & getBall();
			Arkanoid::Buffs::WhatToBuff getBuff();
		};
	}
}

