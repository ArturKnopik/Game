#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "Timer.h"
#include "CollisionChecker.h"
#include "ResourceManager.h"
#include "Animation.h"
namespace Mario
{
	enum AnimationFrameSet
	{
		STOP_LEFT = 0,
		STOP_RIGHT = 1,
		MOVING_LEFT = 2,
		MOVING_RIGHT = 3,
		JUMPING_LEFT = 4,
		JUMPING_RIGHT = 5,
		FALLING_LEFT = 6,
		FALLING_RIGHT = 7,
		DEATH=8,
		STATIC=9

	};

	class Gameobject 
	{
	private:
		size_t id;
		static size_t uid;
	protected:
		sf::Vector2f position;
		sf::Vector2f size;
		System::Animation *currentAnimation;
		AnimationFrameSet currentAnimationSet;
		std::vector<std::pair<AnimationFrameSet, System::Animation>> animationList;
		//state information
		bool isGravityAble = true;
		bool isStatic = false;
		bool isCollisionAble = false;
		//----------------------
		bool moving=false;
		bool isOnGround = false;
		bool canJump = false;
		bool isInFallingState = true;
		bool isInJumpState = true;
		double currentJumpTime;
		double maxJumpingTime;
		bool markedToRemove = false;
	public:
		Gameobject()=delete;

		~Gameobject()=default;

		Gameobject(const sf::Vector2f position, const sf::Vector2f size);

		virtual void draw(std::shared_ptr<sf::RenderWindow> window);

		virtual void update(const double dt)=0;

		System::Animation & getAnimator();

		void changeCurrentAnimation(AnimationFrameSet animation);

		AnimationFrameSet getCurrentAnimationFrameSet();

		virtual void onCollision(std::shared_ptr<Mario::Gameobject> other)=0;

		//position gether
		sf::Vector2f getPosition() { return position; }

		// position setter 
		void setPosition(sf::Vector2f newPosition) { position = newPosition; }

		//size getter
		sf::Vector2f getSize() { return size; }

		// size setter 
		void setSize(sf::Vector2f newSize) { size = newSize; }

		size_t getID();

		void setGravityAble(bool gravityAfected);

		bool getOnGround();

		void setOnGround(bool onGround);

		bool getStatic();

		bool getCollisionAble();

		bool getIsFalling();

		void setIsFalling(bool falling);

		bool getCanJump();

		void setCanJump(bool jump);

		void markToRemove();

		bool getMarkedToRemove();

	};
}

