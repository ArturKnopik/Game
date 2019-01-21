#include "AnimationFrame.h"



Animation::AnimationFrame::AnimationFrame(std::shared_ptr<sf::Texture> texture, float timeToNextFrame)
	:timeToNextFrame(timeToNextFrame)
{
	sprite.setTexture(*texture);
}


Animation::AnimationFrame::~AnimationFrame()
{
}

void Animation::AnimationFrame::setPosition(sf::Vector2f newPosaition)
{
	sprite.setPosition(newPosaition);
}
