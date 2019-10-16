#include "TibiaParticle.h"
#include "SFML/Graphics/Texture.hpp"
#include "TibiaTGCGame.h"
#include "TibiaResoureManager.h"

TGC::Particle::Particle(size_t x, size_t y, std::string textureName)
{
	position.x = x;
	position.y = y;
	if (!animationControler)
	{
		animationControler.emplace(AnimationController());
	}
	texture = TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName(textureName, "particle");
	if (texture)
	{
		particleAnimation.setTexture(texture);
		particleAnimation.addFrame(TGC::Frame(sf::IntRect(0, 0, 32, 32), 0.1));
		particleAnimation.addFrame(TGC::Frame(sf::IntRect(32, 0, 32, 32), 0.1));
		particleAnimation.addFrame(TGC::Frame(sf::IntRect(64, 0, 32, 32), 0.1));
		particleAnimation.addFrame(TGC::Frame(sf::IntRect(96, 0, 32, 32), 0.1));
		particleAnimation.addFrame(TGC::Frame(sf::IntRect(128, 0, 32, 32), 0.1));
		animationControler->play();
		animationControler->setAnimation(particleAnimation);
		this->lifeTimer.second = 0.5;
		return;
	}
	   
	this->lifeTimer.second = 0.0;
}

void TGC::Particle::update(const float dt)
{
	if (animationControler)
	{
		if (texture)
		{
			animationControler->update(dt);
		}
	}
	lifeTimer.first += dt;
	if (lifeTimer.first > lifeTimer.second)
	{
		isLive = false;
	}
}


void TGC::Particle::draw(sf::RenderWindow& renderWindow)
{
	if (animationControler)
	{
		sprite.setTexture(*animationControler->getTexture());
		sprite.setPosition(position.x*Setting::Const::cellSizeX, position.y*Setting::Const::cellSizeY);
		sprite.setTextureRect(animationControler->getAnimation()->getFrame(animationControler->getCurrentFrame()));
		renderWindow.draw(sprite);
	}
}

bool TGC::Particle::isDeath()
{
	if (!isLive)
	{
		return true;
	}
	return false;
}
