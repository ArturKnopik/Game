#include "Mario_GumbaGameObiect.h"




Mario::GumbaGameObiect::GumbaGameObiect(sf::Vector2f position, sf::Vector2f size)
	:Mario::GameObiect(position, size)
{

	System::Animation animationStopLeft(200000);
	animationStopLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationStopLeft.addFrame(sf::IntRect(0, 0, 32, 32));
	System::Animation animationStopRight(200000);
	animationStopRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationStopRight.addFrame(sf::IntRect(0, 32, 32, 32));
	System::Animation animationMovingLeft(200000);
	animationMovingLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Goomba"));
	animationMovingLeft.addFrame(sf::IntRect(0, 0, 32, 32));
	animationMovingLeft.addFrame(sf::IntRect(32, 0, 32, 32));
	System::Animation animationMovingRight(200000);
	animationMovingRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Goomba"));
	animationMovingRight.addFrame(sf::IntRect(0, 32, 32, 32));
	animationMovingRight.addFrame(sf::IntRect(32, 32, 32, 32));
	System::Animation animationJumpingLeft(200000);
	animationJumpingLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationJumpingLeft.addFrame(sf::IntRect(0, 128, 32, 32));
	System::Animation animationJumpingRight(200000);
	animationJumpingRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationJumpingRight.addFrame(sf::IntRect(0, 160, 32, 32));
	System::Animation animationFallingLeft(200000);
	animationFallingLeft.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationFallingLeft.addFrame(sf::IntRect(0, 192, 32, 32));
	System::Animation animationFallingRight(200000);
	animationFallingRight.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("default"));
	animationFallingRight.addFrame(sf::IntRect(0, 224, 32, 32));




	animationList.push_back(std::make_pair(AnimationFrameSet::STOP_LEFT, animationStopLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::STOP_RIGHT, animationStopRight));

	animationList.push_back(std::make_pair(AnimationFrameSet::MOVING_LEFT, animationMovingLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::MOVING_LEFT, animationMovingRight));
	animationList.push_back(std::make_pair(AnimationFrameSet::JUMPING_LEFT, animationJumpingLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::JUMPING_RIGHT, animationJumpingRight));
	animationList.push_back(std::make_pair(AnimationFrameSet::FALLING_LEFT, animationFallingLeft));
	animationList.push_back(std::make_pair(AnimationFrameSet::FALLING_RIGHT, animationFallingRight));

	currentAnimation = &animationList.begin()->second;
	moveDirrectio = Moving::MOVE_LEFT;
	isGravityAble = true;
	isCollisionAble = true;
	isOnGround = false;
	isStatic = false;
	setIsFalling(true);
	setCanJump(false);

}


void Mario::GumbaGameObiect::update(const float dt)
{



	switch (moveDirrectio)
	{
	case Moving::MOVE_LEFT:
		changeCurrentAnimation(Mario::AnimationFrameSet::MOVING_LEFT);
		setPosition(sf::Vector2f(getPosition().x - 0.00009*dt, getPosition().y));
		break;

	case Moving::MOVE_RIGHT:
		changeCurrentAnimation(Mario::AnimationFrameSet::MOVING_RIGHT);
		setPosition(sf::Vector2f(getPosition().x + 0.00009*dt, getPosition().y));
		break;
	}

	if (currentAnimation)
	{
		currentAnimation->update(dt);
		currentAnimation->setSpritePosition(position);
	}
}

void Mario::GumbaGameObiect::onCollision(std::shared_ptr<Mario::GameObiect> other)
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
		moveDirrectio = Moving::MOVE_RIGHT;
		//setPosition(sf::Vector2f(getPosition().x + 0.001, getPosition().y));
		break;
	case System::CollisionType::RIGHT:
		moveDirrectio = Moving::MOVE_LEFT;
		//setPosition(sf::Vector2f(getPosition().x - 0.001, getPosition().y));
		break;
	}

}
