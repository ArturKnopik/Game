#include "Animation.h"
#include <iostream>
#include "ResourceManager.h"

System::Animation::Animation(const double frameTime)
	:currentFrame(0), timeCurrentFrameTime(0), timeMaxFrameTime(frameTime)
{
	sprite.setTexture(*System::ResourceManager::getInstance().getTexture("default"));
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void System::Animation::addFrame(sf::IntRect rect)
{
	frame.push_back(rect);
}

void System::Animation::setSpriteSheetTexture(std::shared_ptr < sf::Texture> texture)
{
	this->texture = texture;
	sprite.setTexture(*texture);
}
std::shared_ptr<sf::Texture> System::Animation::getSpriteSheet()
{
	if (texture)
	{
		return texture;
	}

	printf("NULLPTR TEXTURE");
	return nullptr;

}

std::size_t System::Animation::getSize()
{
	return frame.size();
}

 sf::IntRect& System::Animation::getFrame(std::size_t n)
{
	return frame[n];
}

 sf::Sprite & System::Animation::getSprite()
 {
	//TODO: Safe return sprite if no loaded;
	 return sprite;
 }

 void System::Animation::setFrame(int newFrame, bool restartTimer)
 {
	 if (newFrame > frame.size())
	 {
		 currentFrame = frame.size();
	 }
	 currentFrame = newFrame;
	 
	 sprite.setTextureRect(frame[newFrame]);
	 
 }

 void System::Animation::update(const double dt)
 {
	 timeCurrentFrameTime = timeCurrentFrameTime + dt;
	 if (timeCurrentFrameTime > timeMaxFrameTime)
	 {
		 timeCurrentFrameTime = 0;
		 currentFrame++;
	 }

	 if (currentFrame >= frame.size())
	 {
		 currentFrame = 0;
	 }
	 sprite.setTextureRect(frame[currentFrame]);

 }

 void System::Animation::setSpritePosition(sf::Vector2f position)
 {
	 sprite.setPosition(position);
 }

 void System::NoAnimation::setTexture(std::shared_ptr<sf::Texture> texture)
 {
	 this->texture = texture;
 }

 std::shared_ptr<sf::Texture> System::NoAnimation::getTexture()
 {
	 return texture;
 }

 sf::Sprite & System::NoAnimation::getSprite()
 {
	 return sprite;
 }

 void System::NoAnimation::setSpritePosition(sf::Vector2f position)
 {
	 sprite.setPosition(position);
 }
