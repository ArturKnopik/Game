#include "System_Animation.h"
#include "ResourceManager.h"

System::SpriteAnimationNS::Animation::Animation() : texture(System::ResourceManager::getInstance().getTexture("default"))
{

}


void System::SpriteAnimationNS::Animation::addFrame(sf::IntRect rect)
{
	frames.push_back(rect);
}

void System::SpriteAnimationNS::Animation::setSpriteSheet(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
	sprite.setTexture(*texture);
}

void System::SpriteAnimationNS::Animation::setCustomFrame()
{
}

sf::Sprite & System::SpriteAnimationNS::Animation::getSprite()
{
	return sprite;
}

int System::SpriteAnimationNS::Animation::getSize() 
{
	return frames.size();
}

sf::IntRect System::SpriteAnimationNS::Animation::getFrame(int n)
{
	if (n < frames.size())
	{
		return frames[n];
	}
	else if(frames.size()>0 && frames.size()!=0)
	{
		return frames[0];
	}
	else
	{
		return sf::IntRect(0, 0, 0, 0);
	}
}

