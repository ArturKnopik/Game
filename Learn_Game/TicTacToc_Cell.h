#pragma once
#include <SFML/System/Vector2.hpp>
namespace TicTacToc
{
	class Cell
	{
		char symbol;
		sf::Vector2f position;
		sf::Vector2f size;

	public:
		Cell() = delete;
		Cell(char symbol, sf::Vector2f position, sf::Vector2f size);
		void markCell(char symbol);
		char getSymbol();
		sf::Vector2f getPosition();
		sf::Vector2f getSize();
		~Cell() = default;
	};
}
