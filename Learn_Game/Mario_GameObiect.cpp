
#include <iostream>
#include "SFML/Window/Event.hpp"
#include "Mario_GameObiect.h"
size_t Mario::GameObiect::uid = 0;
size_t Mario::GameObiect::getID()
{
	return id;
}
void Mario::GameObiect::setGravityAble(bool gravityAfected)
{
	isGravityAble = gravityAfected;
}
bool Mario::GameObiect::getOnGround()
{
	return isOnGround;
}
void Mario::GameObiect::setOnGround(bool onGround)
{
	if (onGround)
	{
		setCanJump(true);
	}
	isOnGround = onGround;
}
bool Mario::GameObiect::getStatic()
{
	return isStatic;
}
bool Mario::GameObiect::getCollisionAble()
{
	return isCollisionAble;
}

bool Mario::GameObiect::getIsFalling()
{
	return isInFallingState;
}
void Mario::GameObiect::setIsFalling(bool falling)
{
	isInFallingState = falling;
}
bool Mario::GameObiect::getCanJump()
{
	return isInJumpState;
}
void Mario::GameObiect::setCanJump(bool jump)
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

void Mario::GameObiect::markToRemove()
{
	markedToRemove = true;
}

bool Mario::GameObiect::getMarkedToRemove()
{
	return markedToRemove;
}

Mario::GameObiect::GameObiect(const sf::Vector2f position, const sf::Vector2f size)
	:position(position), size(size)
{
	markedToRemove = false;
	id = uid;
	uid++;
}

void Mario::GameObiect::draw(std::shared_ptr<sf::RenderWindow> window)
{
	
	if (currentAnimation)
	{
		//std::cout<<"Sprite Position: "<<currentAnimation->
		currentAnimation->setSpritePosition(getPosition());
		window->draw(currentAnimation->getSprite());
	}
	
}
/*
void Mario::GameObiect::update(const double dt)
{
	if (currentAnimation)
	{
		currentAnimation->update(dt);
		currentAnimation->setSpritePosition(position);
	}
}
*/
System::Animation & Mario::GameObiect::getAnimator()
{
	return *currentAnimation;
}
void Mario::GameObiect::changeCurrentAnimation(Mario::AnimationFrameSet animation)
{
	currentAnimation = &animationList[animation].second;
	currentAnimationSet = animationList[animation].first;
	return;

	printf("!!! CHANGE ANIMATION ERROR, ANIMATION NOT FOUND !!!");
}
Mario::AnimationFrameSet Mario::GameObiect::getCurrentAnimationFrameSet()
{
	return currentAnimationSet;
}
/*
void Mario::GameObiect::onCollision(std::shared_ptr<Mario::GameObiect> other)
{
}
*/


