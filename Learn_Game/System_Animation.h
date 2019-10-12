#pragma once

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
namespace System
{
	namespace SpriteAnimationNS
	{
		struct SpriteAnimation
		{
			enum AnimationType { NO_ANIMATED_SINGLE_FRAME = 1,
								 ANIMATED_SINGLE_FRAME = 2, 
								 NO_ANIMATED_MULTIPLE_FRAME = 3, 
								 ANIMATED_MULTIPLE_FRAME = 4 };
			enum SpriteFrame {  LD = 1,
								CD = 2,
								RD = 3,
								CL = 4,
								CC = 5,
								CR = 6,
								LU = 7,
								CU = 8,
								RU = 9 };
			AnimationType animationType;
			SpriteFrame currentSpriteFrame;
		};
		// Class controll animations
		class Animation
		{
		private:
			sf::Sprite sprite;
			std::vector<sf::IntRect> frames;
			std::shared_ptr<sf::Texture> texture;
			void addFrame(sf::IntRect rect);
		public:
			// Derafault c'tor
			Animation();
			//Animation(std::shared_ptr<sf::Texture> texture, SpriteAnimation spriteAnimation);
			void setSpriteSheet(std::shared_ptr<sf::Texture> texture);
			void setCustomFrame();
			sf::Sprite & getSprite();
			int getSize();
			sf::IntRect getFrame(int n);
		};

	}
}
