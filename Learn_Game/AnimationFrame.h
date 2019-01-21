#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
namespace Animation
{
	class AnimationFrame
	{
		sf::Sprite sprite;
		float timeToNextFrame;
	public:
		AnimationFrame(std::shared_ptr<sf::Texture> texture, float timeToNextFrame=30000);
		~AnimationFrame();
		void setPosition(sf::Vector2f newPosaition);
	};
}

