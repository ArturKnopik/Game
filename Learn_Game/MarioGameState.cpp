#include "MarioGameState.h"
#include "ResourceManager.h"

MarioGameState::MarioGameState(std::shared_ptr<Game> game)
	:player(sf::Vector2f(100,100),sf::Vector2f(32,32),System::ResourceManager::getInstance().getTexture("default"))
{
	this->game = game;
}

void MarioGameState::draw()
{
	player.draw(game->window);
}

void MarioGameState::update(const float dt)
{
	player.update(dt);
}

void MarioGameState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game->window->close();
	}
	player.input(event);
}


MarioGameState::~MarioGameState()
{
}
