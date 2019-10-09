#pragma once
#include <SFML/System/Vector2.hpp>
#include <memory>
#include<SFML/Graphics.hpp>
#include "Arkanoid_Paddle.h"
#include "Arkanoid_IBuff.h"
namespace Arkanoid
{
	class Ball
	{
		double speed;
		sf::Vector2f position;
		sf::Vector2f speedValue;
		sf::Vector2f oldPosition;
		double oryginalRadius;
		double radius;
		double currentSpeed;
		double angle;
		bool updateAble;
		void updateBuffs(const double dt);
	public:
		Ball();
		Ball(sf::Vector2f position, double radius);
		virtual ~Ball()=default;
		double speedMultipler;
		void update(const double dt);
		void increaseSpeed();
		void decreaseSpeed();
		void resetSpeed();
		const sf::Vector2f getPosition() const;
		const double getRadius() const;
		void changeSize(double radius);
		void resetRadius();
		void setRadius(double radius);
		void setHitAngle(const Arkanoid::Paddle & paddle);
		void reverseXSpeed();
		void reverseYSpeed();
		const double getAngle() const;
		void setPosition(sf::Vector2f pos);
		void setUpdateAble(bool uA);
		bool getUpdateAble();
	};
}


