#include "Mario_MarioGameobject.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Mario::MarioGameobject::MarioGameobject(sf::Vector2f position, sf::Vector2f size)
	:Gameobject(sf::Vector2f(100,100), sf::Vector2f(32,32))
{
	System::Animation animationStopLeft(200000);
	animationStopLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationStopLeft.addFrame(sf::IntRect(0, 0, 32, 32));
	System::Animation animationStopRight(200000);
	animationStopRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationStopRight.addFrame(sf::IntRect(0, 32, 32, 32));
	System::Animation animationMovinLeft(200000);
	animationMovinLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationMovinLeft.addFrame(sf::IntRect(0, 64, 32, 32));
	animationMovinLeft.addFrame(sf::IntRect(32, 64, 32, 32));
	animationMovinLeft.addFrame(sf::IntRect(64, 64, 32, 32));
	System::Animation animationMovinRight(200000);
	animationMovinRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationMovinRight.addFrame(sf::IntRect(0, 96, 32, 32));
	animationMovinRight.addFrame(sf::IntRect(32, 96, 32, 32));
	animationMovinRight.addFrame(sf::IntRect(64, 96, 32, 32));
	System::Animation animationJumpingLeft(200000);
	animationJumpingLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationJumpingLeft.addFrame(sf::IntRect(0, 128, 32, 32));
	System::Animation animationJumpingRight(200000);
	animationJumpingRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationJumpingRight.addFrame(sf::IntRect(0, 160, 32, 32));
	System::Animation animationFallingLeft(200000);
	animationFallingLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationFallingLeft.addFrame(sf::IntRect(0, 192, 32, 32));
	System::Animation animationFallingRight(200000);
	animationFallingRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Mario"));
	animationFallingRight.addFrame(sf::IntRect(0, 224, 32, 32));




	animationList.push_back(std::make_pair(AnimationFrameSet::STOP_LEFT, animationStopLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::STOP_RIGHT, animationStopRight));

	animationList.push_back(std::make_pair(AnimationFrameSet::MOVING_LEFT, animationMovinLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::MOVING_RIGHT, animationMovinRight));
	animationList.push_back(std::make_pair(AnimationFrameSet::JUMPING_LEFT, animationJumpingLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::JUMPING_RIGHT, animationJumpingRight));
	animationList.push_back(std::make_pair(AnimationFrameSet::FALLING_LEFT, animationFallingLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::FALLING_RIGHT, animationFallingRight));


	currentAnimation = &animationList[1].second;
	isGravityAble = true;
	isCollisionAble = true;
	isOnGround = false;
	isStatic = false;
	setIsFalling(true);
	setCanJump(false);

	currentJumpTime = 0;
	maxJumpingTime = 600000;
}

void Mario::MarioGameobject::update(const double dt)
{
	if (currentAnimation)
	{
		currentAnimation->update(dt);
		currentAnimation->setSpritePosition(position);
	}

	
	if (getIsFalling() && !getOnGround() )
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			setPosition(sf::Vector2f(getPosition().x - 0.0001*dt, getPosition().y));
			changeCurrentAnimation(Mario::AnimationFrameSet::FALLING_LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			setPosition(sf::Vector2f(getPosition().x + 0.0001*dt, getPosition().y));
			changeCurrentAnimation(Mario::AnimationFrameSet::FALLING_RIGHT);
		}
		else
		{
			if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_LEFT
				)
			{
				changeCurrentAnimation(Mario::AnimationFrameSet::FALLING_LEFT);
			}
			else if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_RIGHT)
			{
				changeCurrentAnimation(Mario::AnimationFrameSet::FALLING_RIGHT);
			}
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			setPosition(sf::Vector2f(getPosition().x - 0.0001*dt, getPosition().y));
			changeCurrentAnimation(Mario::AnimationFrameSet::MOVING_LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			setPosition(sf::Vector2f(getPosition().x + 0.0001*dt, getPosition().y));
			changeCurrentAnimation(Mario::AnimationFrameSet::MOVING_RIGHT);
		}
		else if (getOnGround())
		{
			if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_LEFT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_LEFT
				)
			{
				changeCurrentAnimation(Mario::AnimationFrameSet::STOP_LEFT);
			}
			else if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_RIGHT ||
				getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_RIGHT)
			{
				changeCurrentAnimation(Mario::AnimationFrameSet::STOP_RIGHT);
			}
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !getOnGround())
		{
			setCanJump(false);
			setIsFalling(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getCanJump())
		{
			if (currentJumpTime < maxJumpingTime && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					setPosition(sf::Vector2f(getPosition().x - 0.0001*dt, getPosition().y));
					changeCurrentAnimation(Mario::AnimationFrameSet::JUMPING_LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					setPosition(sf::Vector2f(getPosition().x + 0.0001*dt, getPosition().y));
					changeCurrentAnimation(Mario::AnimationFrameSet::JUMPING_RIGHT);
				}

				currentJumpTime = currentJumpTime + dt;
				setPosition(sf::Vector2f(getPosition().x, getPosition().y - 0.0004*dt));
				setOnGround(false);
				if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_LEFT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_LEFT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_LEFT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_LEFT
					)
				{
					changeCurrentAnimation(Mario::AnimationFrameSet::JUMPING_LEFT);
				}
				else if (getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::MOVING_RIGHT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::FALLING_RIGHT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::JUMPING_RIGHT ||
					getCurrentAnimationFrameSet() == Mario::AnimationFrameSet::STOP_RIGHT)
				{
					changeCurrentAnimation(Mario::AnimationFrameSet::JUMPING_RIGHT);
				}
			}
			else
			{
				setCanJump(false);
				setIsFalling(true);

			}

		}
		else
		{

		}

	}
}



Mario::MarioGameobject::~MarioGameobject()
{

}

void Mario::MarioGameobject::onCollision(std::shared_ptr<Mario::Gameobject> other)
{
	System::CollisionType collisionSite = System::getCollsionSite(other->getPosition(), other->getSize(), getPosition(), getSize());
	switch (collisionSite)
	{
	case System::CollisionType::TOP:
		setCanJump(false);
		setIsFalling(true);
		break;
	case System::CollisionType::BOTTOM:
		setCanJump(true);
		setIsFalling(false);
		break;
	case System::CollisionType::LEFT:
		//setIsFalling(true);
		break;
	case System::CollisionType::RIGHT:
		//setIsFalling(true);
		break;
	}
}


