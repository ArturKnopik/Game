#pragma once

#include "BasicButton.h"
#include "Game.h"
#include <iostream>
#include "GameState.h"
#include "BasicButton.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

class MenuState : public GameState {
private:
	sf::Event event;
	short menuSwitch = 1;
	sf::Font font;
	void loadGameMenu();
	std::vector<std::unique_ptr<Button>> menuButtonElements;
public:

	MenuState() = delete;
	MenuState(std::shared_ptr<Game> game);
	void draw();
	void update(const double dt);
	void input();
	virtual ~MenuState()=default;
};

