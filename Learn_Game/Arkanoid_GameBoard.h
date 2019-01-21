#pragma once
#include <SFML/System/Vector2.hpp>
namespace Arkanoid
{
	class GameBoard
	{
		sf::Vector2f position;
		sf::Vector2f size;
	public:
		GameBoard();
		GameBoard(float x, float y, float w, float h);
		GameBoard(sf::Vector2f position, sf::Vector2f size);
		virtual ~GameBoard();
		const sf::Vector2f getPosition();
		const sf::Vector2f getSize();
	};
}

