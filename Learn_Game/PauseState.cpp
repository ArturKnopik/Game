#include "PauseState.h"
#include <iostream>




PauseState::PauseState(std::shared_ptr<Game> game)
{
	this->game = game;
	game->window->setView(game->window->getDefaultView());
	std::cout << "Create PauseStatew - ";
}

PauseState::~PauseState()
{
	std::cout << "Destroy PauseState - ";
}

void PauseState::draw()
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(100, 100));
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Blue);
	game->window->draw(rect);
}

void PauseState::update(const double dt)
{
}

void PauseState::input()
{


	while (game->window->pollEvent(*event))
	{
		switch (event->type)
		{
			/* Close the window */
		case sf::Event::Closed:
			game->window->close();
			break;

			/* Change Between game states */
		case sf::Event::KeyPressed:
			if (event->key.code == sf::Keyboard::Escape)
			{
				game->popState();
			}
			if (event->key.code == sf::Keyboard::Q)
			{
				game->popState();
				game->popState();
			}

		}
	}
}
