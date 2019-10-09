#pragma once
#include <vector>
#include "AnimationFrame.h"
namespace System
{
	class Animation
	{
	private:
		std::vector<sf::IntRect> frame;
		std::shared_ptr<sf::Texture> texture;
		size_t currentFrame;
		double timeMaxFrameTime;
		double timeCurrentFrameTime;
		sf::Sprite sprite;
	public:
		Animation(const double frameTime);

		void addFrame(sf::IntRect rect);
		void setSpriteSheetTexture(std::shared_ptr < sf::Texture>);
		std::shared_ptr <sf::Texture> getSpriteSheet();
		std::size_t getSize();
		sf::IntRect & getFrame(std::size_t n);
		sf::Sprite & getSprite();
		void setFrame(int frame, bool restartTimer = false);
		void update(const double dt);
		void setSpritePosition(sf::Vector2f position);

	
	};
	class NoAnimation
	{
	private:
		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
	public:
		void setTexture(std::shared_ptr < sf::Texture> texture);
		std::shared_ptr <sf::Texture> getTexture();
		sf::Sprite & getSprite();
		void setSpritePosition(sf::Vector2f position);
	};
}

