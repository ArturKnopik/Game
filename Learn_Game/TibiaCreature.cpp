#include "TibiaCreature.h"
#include "TibiaTGCGame.h"
#include "SFML/Window/Mouse.hpp"
//	Global::TGCGame::getSingleton().addMoveRequest(reinterpret_cast<Creature*>(this->getCreature()) , dir)

bool TGC::Creature::canWalk()
{
	if (currentWalikingTime >= walkingTime)
	{
		return true;
	}
	return false;
}

void TGC::Creature::update(const float dt)
{
	double tempDt = dt / 1000000; // used to 
	if (currentWalikingTime < walkingTime)
	{
		if (animationControler)
		{
			calculateSpriteOfsetPercentDone();
			applySpriteOfset();
			animationControler->update(tempDt);
		}
		currentWalikingTime += tempDt;
	}
	else
	{
		if (animationControler)
		{
			animationControler->stop();
			positionSprite.x = position.x * 32;
			positionSprite.y = position.y * 32;
		}
	}
}

bool TGC::Creature::canPlayWalikngAnimation()
{
	return walkAnimation;
}
void TGC::Creature::calculateSpriteOfsetPercentDone()
{
	const double cellSizeOnePercent = 32.0/100.0;
	double walkPercentDone = walkingTime / 100;
	double currentPercent =  currentWalikingTime / walkingTime * 100.0;

	switch (direction)
	{
	case ENUMS::Direction::UP:
		spriteOfset.y = cellSizeOnePercent * currentPercent -32;
		spriteOfset.x = 0;
		break;
	case ENUMS::Direction::DOWN:
		spriteOfset.y = cellSizeOnePercent * (currentPercent * -1) +32;
		spriteOfset.x = 0;
		break;
	case ENUMS::Direction::LEFT:
		spriteOfset.x = cellSizeOnePercent * currentPercent-32;
		spriteOfset.y = 0;;
		break;
	case ENUMS::Direction::RIGHT:
		spriteOfset.x = cellSizeOnePercent * (currentPercent*-1) +32;
		spriteOfset.y = 0;
		break;
	}
}

void TGC::Creature::applySpriteOfset()
{
	if (spriteMoving)
	{
		positionSprite.x = getPosition().x * 32 + spriteOfset.x * -1;
		positionSprite.y = getPosition().y * 32 + spriteOfset.y * -1;
	}
	else
	{
		positionSprite.x = getPosition().x * 32  ;
		positionSprite.y = getPosition().y * 32 ;
	}
}

bool TGC::Creature::isSpriteMoving()
{
	return false;
}

void TGC::Creature::setName(std::string name)
{
	this->name = name;
}

void TGC::Creature::setWalkingTime(double time)
{
	this->walkingTime = time;
}

void TGC::Creature::setAnimation(ENUMS::Direction animationDir, Animation animation)
{
	switch (animationDir)
	{
	case ENUMS::Direction::UP:
		animationUp = std::move(animation);
		break;
	case ENUMS::Direction::DOWN:
		animationDown = std::move(animation);
		break;
	case ENUMS::Direction::LEFT:
		animationLeft = std::move(animation);
		break;
	case ENUMS::Direction::RIGHT:
		animationRight = std::move(animation);
		break;
	}
}

void TGC::Creature::drawHealthBar(sf::RenderWindow& renderWindow)
{
	sf::RectangleShape backgrounRect;
	backgrounRect.setSize(sf::Vector2f(Setting::Const::cellSizeX, 5));
	backgrounRect.setPosition(positionSprite.x, positionSprite.y-5);
	backgrounRect.setFillColor(sf::Color::Black);
	sf::RectangleShape healthRect;
	healthRect.setPosition(positionSprite.x+1, positionSprite.y-5);
	healthRect.setFillColor(sf::Color::Green);


	double healthRectWidth = (Setting::Const::cellSizeX-2);
	healthRectWidth *= (1.0 * currentHP / maxHP);
	healthRect.setSize(sf::Vector2f(healthRectWidth, 3));
	renderWindow.draw(backgrounRect);
	renderWindow.draw(healthRect);


}


void TGC::Creature::setWalkingAnimation(bool walkAnim, ENUMS::Direction direction)
{
	this->spriteMoving = walkAnim;
	positionSprite.x = position.x*32;
	positionSprite.y = position.y*32;
	
	if (animationControler)
	{
		switch (direction)
		{
		case ENUMS::Direction::UP:
			animationControler->setAnimation(animationUp);
			animationControler->play();
			direction = ENUMS::Direction::UP;
			break;
		case ENUMS::Direction::DOWN:
			animationControler->setAnimation(animationDown);
			animationControler->play();
			direction = ENUMS::Direction::DOWN;
			break;
		case ENUMS::Direction::LEFT:
			animationControler->setAnimation(animationLeft);
			animationControler->play();
			direction = ENUMS::Direction::LEFT;
			break;
		case ENUMS::Direction::RIGHT:
			animationControler->setAnimation(animationRight);
			animationControler->play();
			direction = ENUMS::Direction::RIGHT;
			break;
		}
	}

}

void TGC::Creature::setDirection(ENUMS::Direction dir)
{
	direction = dir;
}

void TGC::Creature::draw(sf::RenderWindow& renderWindow)
{
	if (animationControler)
	{
		sprite.setTexture(*animationControler->getTexture());
		sprite.setPosition(positionSprite.x, positionSprite.y);
		sprite.setTextureRect(animationControler->getAnimation()->getFrame(animationControler->getCurrentFrame()));
		renderWindow.draw(sprite);
	}
	drawHealthBar(renderWindow);
}

void TGC::Creature::setSpriteMoving(bool spriteMoving)
{
	this->spriteMoving = spriteMoving;
}

void TGC::Creature::restartWalkingTime(bool canWalk)
{
	if (canWalk)
	{
		currentWalikingTime = walkingTime * 2;
	}
	else
	{
		currentWalikingTime = 0;
	}
}


void TGC::Creature::setTarget(std::shared_ptr<Creature> creature)
{
	targetCreature = creature;
}

const std::shared_ptr<TGC::Creature>  TGC::Creature::getTarget() const
{
	if (targetCreature)
	{
		return targetCreature;
	}
	else
	{
		return nullptr;
	}
}

void TGC::Creature::setHealth(unsigned int health)
{
	currentHP = health;
}

unsigned int TGC::Creature::getHealth()
{
	return currentHP;
}

void TGC::Creature::setMaxHeatlh(unsigned int health)
{
	maxHP = health;
}

unsigned int TGC::Creature::getMaxHealth()
{
	return maxHP;
}


TGC::ENUMS::Direction * TGC::Creature::getDirection()
{
	return &direction;
}

TGC::Creature::Creature()
{ 
	spriteOfset.x = walkingTime / Setting::Const::FPS;
	spriteOfset.y = walkingTime / Setting::Const::FPS;
	animationControler->setAnimation(animationDown);
	positionSprite.x = getPosition().x * Setting::Const::cellSizeX;
	positionSprite.y = getPosition().y * Setting::Const::cellSizeY;
	sprite.setPosition(positionSprite.x, positionSprite.y);
}

TGC::Creature* TGC::Creature::getCreature()
{
	return this;
}

TGC::Creature& TGC::Creature::getReferenceThis()
{
	return *this;
}

const std::string& TGC::Creature::getName() const
{
	return name;
};

void TGC::Creature::sendMoveRequest(ENUMS::Direction dir)
{
	if (canWalk())
	{
		restartWalkingTime(false);
		Global::TGCGame& gamePRT = TGC::Global::TGCGame::getSingleton();
		gamePRT.addMoveRequest(this, dir);
		direction = dir;
	}
}


