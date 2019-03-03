#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
namespace AnimationComponents
{
	class AnimationFrame
	{
		sf::Sprite sprite;
		float timeToNextFrame;
	public:
		AnimationFrame() = delete;
		AnimationFrame(std::shared_ptr<sf::Texture> texture, sf::IntRect intRect, float timeToNextFrame );
		~AnimationFrame();
		void setPosition(sf::Vector2f newPosaition);
		sf::Sprite & getSprite();
	};
}

