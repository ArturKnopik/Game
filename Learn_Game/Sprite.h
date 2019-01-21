#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <string>
#include <memory>
#include <vector>
namespace kr
{
	enum SpriteType
	{
		STATIC,
		STATIC_ANIMATED,
		ROTATEABLE_ANIMATED
	};
	class Sprite
	{
	private:
		SpriteType spriteType;
		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
		std::vector<std::vector<sf::IntRect>> intRectSpriteMatrix;

	public:
		Sprite();
		Sprite(std::string url);
		Sprite(std::string url, SpriteType spriteType);
		Sprite(std::shared_ptr<sf::Texture> texture);
		Sprite(std::shared_ptr<sf::Texture> texture, SpriteType spriteType);
		void setTexture(std::shared_ptr<sf::Texture> texture);
		void setTexture(std::shared_ptr<sf::Texture> texture, const SpriteType spriteType);
		void draw(std::shared_ptr<sf::RenderWindow> window);
		void setX(float x);
		void setY(float y);
		void setCurretTextureRect(const int col, const int row);
		~Sprite();
	};
}

