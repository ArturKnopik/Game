#pragma once
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
namespace Arkanoid
{
	class Block
	{
		enum BlockType
		{
			INDESTRUCTIBLE,
			DESTRUCTIBLE
		};
		BlockType blockType;
		sf::Vector2f position;
		sf::Vector2f size;
		sf::Vector2f center;
		int life;
	public:
		Block() = delete;
		Block(double x, double y, double width, double height, int life);
		Block(sf::Vector2f position, sf::Vector2f size, int life);
		virtual void setSize(sf::Vector2f size);
		virtual void setPosition(sf::Vector2f position);
		virtual void removeLife();
		virtual void update(const double dt);
		const sf::Vector2f getCenter();
		int getCurrentLife();
		const sf::Vector2f getPosition();
		const sf::Vector2f getSize();
		virtual ~Block();
	};
}

