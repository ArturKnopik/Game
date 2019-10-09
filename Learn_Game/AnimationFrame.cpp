#include "AnimationFrame.h"



AnimationComponents::AnimationFrame::AnimationFrame(std::shared_ptr<sf::Texture> texture, sf::IntRect intRect, double timeToNextFrame = 30000)
	:timeToNextFrame(timeToNextFrame)
{
	sprite.setTextureRect(intRect);
	sprite.setTexture(*texture);
}


AnimationComponents::AnimationFrame::~AnimationFrame()
{
}

void AnimationComponents::AnimationFrame::setPosition(sf::Vector2f newPosaition)
{
	sprite.setPosition(newPosaition);
}

sf::Sprite & AnimationComponents::AnimationFrame::getSprite()
{
	return sprite;
}
