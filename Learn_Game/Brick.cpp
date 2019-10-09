#include "Brick.h"



Brick::Brick(sf::Vector2f position, sf::Vector2f size)
	:GameObiect(position, size)
{
	isGravityAble = false;
	isStatic = true;
	isCollisionAble = true;
	isOnGround = false;

	System::Animation image(200000);
	image.setSpriteSheetTexture(System::ResourceManager::getInstance().getTexture("Brick"));
	image.addFrame(sf::IntRect(0, 0, 32, 32));
	animationList.push_back(std::make_pair(Mario::AnimationFrameSet::STATIC, image));
	currentAnimation = &animationList.begin()->second;
}

void Brick::update(const double dt)
{
	if (currentAnimation)
	{
		currentAnimation->update(dt);
		currentAnimation->setSpritePosition(position);
	}
}


Brick::~Brick()
{
}

void Brick::onCollision(std::shared_ptr<Mario::GameObiect> other)
{
	System::CollisionType collisionSite = System::getCollsionSite(other->getPosition(), other->getSize(), getPosition(), getSize());
	switch (collisionSite)
	{
	case System::CollisionType::TOP:
		other->setCanJump(true);
		other->setIsFalling(false);
		other->setOnGround(true);
		other->setPosition(sf::Vector2f(other->getPosition().x, getPosition().y - other->getSize().y));
		break;
	case System::CollisionType::BOTTOM:
		other->setCanJump(false);
		other->setIsFalling(true);
		other->setPosition(sf::Vector2f(other->getPosition().x, getPosition().y + other->getSize().y));
		break;
	case System::CollisionType::LEFT:
		other->setPosition(sf::Vector2f(getPosition().x-other->getSize().x+0.00001,  other->getPosition().y));
		//other->setPosition(100 , );
		break;
	case System::CollisionType::RIGHT:
		other->setPosition(sf::Vector2f(getPosition().x +getSize().x - 0.00001, other->getPosition().y));
		break;
	}
	
}
