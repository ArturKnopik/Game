#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuState.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "MenuState.h"

int main()
{	srand(time(NULL));
	std::shared_ptr<Game> game = std::make_shared<Game>();
	game->pushState(std::make_shared<MenuState>(game));
	game->gameLoop();
	return 0;
}