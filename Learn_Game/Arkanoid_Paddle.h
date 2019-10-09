#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/Keyboard.hpp>
namespace Arkanoid
{
	enum Direction
	{
		LEFT,
		RIGHT,
		STOP
	};
	class Paddle
	{
		sf::Vector2f position;
		sf::Vector2f size;
		Direction dir=STOP;
		void moveLeft(const double dt);
		void moveRight(const double dt);
		int life;
	public:
		Paddle();
		~Paddle();
		void removeLife();
		void addLife();
		const int getCurrentLife() const;
		void draw(std::shared_ptr<sf::RenderWindow> window);
		void update(const double dt);
		void setDirection(Direction dir);
		void input(std::shared_ptr<sf::Event> event);
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getSize() const;
		sf::Vector2f getPosition() const ;
		void setSize(sf::Vector2f size);
	};
}

