

#include "Game.h"
#include "GameState.h"
#include <iostream>
#include "settings.h"

Game::Game()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window = std::make_shared<sf::RenderWindow>();
	window->create(sf::VideoMode(WIDTH, HEIGHT), "Mario Clone", sf::Style::None, settings);
	window->setFramerateLimit(FPS);

}

void Game::pushState(std::shared_ptr<GameState> state)
{
	states.push_back(state);
}

void Game::popState() {
	if (!states.empty())
	{
		states.pop_back();
	}
}

Game::~Game()
{
	while (!states.empty())
		popState();
}

std::shared_ptr<GameState> Game::currentState()
{
	if (states.empty())
	{
		return nullptr;
	}
	else
	{
		return states.back();
	}
}

void Game::gameLoop()
{
	sf::Clock clock;
	while (window->isOpen())
	{
		sf::Time elapsed = clock.restart();
		float  dt = elapsed.asMicroseconds();
		currentState()->input();
		currentState()->update(dt);
		window->clear();
		currentState()->draw();
		window->display();
	}
}
