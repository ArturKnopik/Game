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
		float speed;
		sf::Vector2f position;
		sf::Vector2f speedValue;
		sf::Vector2f oldPosition;
		float oryginalRadius;
		float radius;
		float currentSpeed;
		float angle;
		bool updateAble;
		void updateBuffs(const float dt);
	public:
		Ball();
		Ball(sf::Vector2f position, float radius);
		virtual ~Ball()=default;
		float speedMultipler;
		void update(const float dt);
		void increaseSpeed();
		void decreaseSpeed();
		void resetSpeed();
		const sf::Vector2f getPosition() const;
		const float getRadius() const;
		void changeSize(float radius);
		void resetRadius();
		void setRadius(float radius);
		void setHitAngle(const Arkanoid::Paddle & paddle);
		void reverseXSpeed();
		void reverseYSpeed();
		const float getAngle() const;
		void setPosition(sf::Vector2f pos);
		void setUpdateAble(bool uA);
		bool getUpdateAble();
	};
}


