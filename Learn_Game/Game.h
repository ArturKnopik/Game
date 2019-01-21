#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <memory>
#include <utility>
class GameState;

class Game
{
public:
	Game();
	~Game();


	void pushState(std::shared_ptr<GameState> state);
	void popState();

	std::shared_ptr<GameState> currentState();

	void gameLoop();

	std::shared_ptr<sf::RenderWindow> window;


private:
	std::vector<std::shared_ptr<GameState>> states;

};
