
#include <iostream>
#include "SFML/Window/Event.hpp"
#include "Mario_Gameobject.h"
size_t Mario::Gameobject::uid = 0;
size_t Mario::Gameobject::getID()
{
	return id;
}
void Mario::Gameobject::setGravityAble(bool gravityAfected)
{
	isGravityAble = gravityAfected;
}
bool Mario::Gameobject::getOnGround()
{
	return isOnGround;
}
void Mario::Gameobject::setOnGround(bool onGround)
{
	if (onGround)
	{
		setCanJump(true);
	}
	isOnGround = onGround;
}
bool Mario::Gameobject::getStatic()
{
	return isStatic;
}
bool Mario::Gameobject::getCollisionAble()
{
	return isCollisionAble;
}

bool Mario::Gameobject::getIsFalling()
{
	return isInFallingState;
}
void Mario::Gameobject::setIsFalling(bool falling)
{
	isInFallingState = falling;
}
bool Mario::Gameobject::getCanJump()
{
	return isInJumpState;
}
void Mario::Gameobject::setCanJump(bool jump)
{
	if (jump == true)
	{
		currentJumpTime = 0;
	}
	else if (jump == false)
	{
		currentJumpTime = maxJumpingTime + 1;
	}
	this->isInJumpState = jump;
}

void Mario::Gameobject::markToRemove()
{
	markedToRemove = true;
}

bool Mario::Gameobject::getMarkedToRemove()
{
	return markedToRemove;
}

Mario::Gameobject::Gameobject(const sf::Vector2f position, const sf::Vector2f size)
	:position(position), size(size)
{
	markedToRemove = false;
	id = uid;
	uid++;
}

void Mario::Gameobject::draw(std::shared_ptr<sf::RenderWindow> window)
{
	
	if (currentAnimation)
	{
		//std::cout<<"Sprite Position: "<<currentAnimation->
		currentAnimation->setSpritePosition(getPosition());
		window->draw(currentAnimation->getSprite());
	}
	
}
/*
void Mario::Gameobject::update(const double dt)
{
	if (currentAnimation)
	{
		currentAnimation->update(dt);
		currentAnimation->setSpritePosition(position);
	}
}
*/
System::Animation & Mario::Gameobject::getAnimator()
{
	return *currentAnimation;
}
void Mario::Gameobject::changeCurrentAnimation(Mario::AnimationFrameSet animation)
{
	currentAnimation = &animationList[animation].second;
	currentAnimationSet = animationList[animation].first;
	return;

	printf("!!! CHANGE ANIMATION ERROR, ANIMATION NOT FOUND !!!");
}
Mario::AnimationFrameSet Mario::Gameobject::getCurrentAnimationFrameSet()
{
	return currentAnimationSet;
}
/*
void Mario::Gameobject::onCollision(std::shared_ptr<Mario::Gameobject> other)
{
}
*/


