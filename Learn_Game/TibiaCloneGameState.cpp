#include "TibiaCloneGameState.h"
#include "SFML/Graphics/View.hpp"
#include "PauseState.h"
void TGC::TibiaCloneGameState::draw()
{
	camera.updateCamera(TGC::Global::TGCGame::getSingleton().getPlayer());
	game->window->setView(camera.getViewe());
	auto& gameSingleton = Global::TGCGame::getSingleton();
	tcgGame->draw(*game->window);
}

void TGC::TibiaCloneGameState::update(const double dt)
{
	TGC::Global::TGCGame::getSingleton().updateWorld(dt, TGC::Global::TGCGame::getSingleton().getPlayer());
}

void TGC::TibiaCloneGameState::input()
{
	while (this->game->window->pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
			this->game->window->close();
			break;

			//pause game
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				game->pushState(std::move(std::make_unique<PauseState>(game)));
			break;

		}
	}
	Global::TGCGame::getSingleton().input(event);
}

TGC::TibiaCloneGameState::TibiaCloneGameState(std::shared_ptr<Game> game)
{
	tcgGame = &Global::TGCGame::getSingleton();
	tcgGame->setWindow(*game->window);
	camera = TGC::Camera::CameraController(TGC::Global::TGCGame::getSingleton().getPlayer(), *game->window);
	this->game = game;
}

TGC::TibiaCloneGameState::~TibiaCloneGameState()
{
}
