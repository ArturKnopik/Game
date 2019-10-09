#pragma once
#include "Game.h"
//#include <memory>
class GameState {
protected :
	std::shared_ptr<sf::Event> event;
	std::shared_ptr<Game> game;
public:
	GameState();
	
	virtual void draw() = 0;

	virtual void update(const double dt) = 0;

	virtual void input() = 0;

	virtual ~GameState()=default;
};

