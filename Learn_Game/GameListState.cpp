#include "GameListState.h"
#include "BasicButton.h"
#include "Arkanoid_BasicBrawStyle.h"
#include "ArkanoidPlayingGameState.h"
#include "TicTacTocGameState.h"
#include "MarioGameState.h"
#include "TibiaCloneGameState.h"
GameListState::GameListState(std::shared_ptr<Game> game)
{

	this->game = game;	
	gameListButtons.push_back(std::unique_ptr<Button>(new BasicButton("TIBIA CLONE (WIP)", sf::Vector2f(100, 100), sf::Vector2f(600, 50), 50, sf::Color(0, 100, 200, 150), sf::Color(255, 0, 0, 180))));
	gameListButtons.push_back(std::unique_ptr<Button>(new BasicButton("TIC-TAC-TOC", sf::Vector2f(100, 200), sf::Vector2f(600, 50), 50, sf::Color(0, 100, 200, 150), sf::Color(255, 0, 0, 180))));
	gameListButtons.push_back(std::unique_ptr<Button>(new BasicButton("ARKANOID", sf::Vector2f(100, 300), sf::Vector2f(600, 50), 50, sf::Color(0, 100, 200, 150), sf::Color(255, 0, 0, 180))));
	gameListButtons.push_back(std::unique_ptr<Button>(new BasicButton("MARIO CLONE", sf::Vector2f(100, 400), sf::Vector2f(600, 50), 50, sf::Color(0, 100, 200, 150), sf::Color(255, 0, 0, 180))));
	for (auto it = gameListButtons.begin(); it != gameListButtons.end(); it++)
	{
		(*it)->noActived();
	}
	gameListButtons[0]->Actived();
}

void GameListState::draw()
{
	
	for (auto it = gameListButtons.begin(); it != gameListButtons.end(); it++)
	{
		(*it)->draw(game->window);
	}
	
}

void GameListState::update(const double dt)
{
	//activeGameRect.setPosition(47, 47+(currentMarkedGame*50));
}

void GameListState::input()
{
	while (game->window->pollEvent(*event)) {
		switch (event->type) {
			/* Close the window */
		case sf::Event::Closed:
			game->window->close();
			break;

			/* Change Between game states */
		case sf::Event::KeyPressed:
			if (event->key.code == sf::Keyboard::Escape) {
				game->popState();
			}
			if (event->key.code == sf::Keyboard::Return) {
				switch (currentMarkedGame)
				{
				case 0:
					game->pushState(std::move(std::unique_ptr<TGC::TibiaCloneGameState>(new TGC::TibiaCloneGameState(game))));
					break;
				case 1:
					game->pushState(std::unique_ptr<GameState>(new TicTacToc::TicTacTocGameState(game)));

					break;
				case 2:
					game->pushState(std::unique_ptr<GameState>(new TetrisGameState(game, std::unique_ptr<Arkanoid::IDrawStyle>(new Arkanoid::BasicBrawStyle()))));
					break;
				case 3:
					game->pushState(std::unique_ptr<GameState>(new MarioGameState(game)));
					break;
				}
				
			}


			if (event->key.code == sf::Keyboard::Up) {
				for (auto it = gameListButtons.begin(); it != gameListButtons.end(); it++)
				{
					(*it)->noActived();
				}
				if (currentMarkedGame == 0)
				{
					currentMarkedGame = gameListButtons.size() - 1;
				}
				else
				{
					currentMarkedGame--;
				}
			}

			if (event->key.code == sf::Keyboard::Down) {
				for (auto it = gameListButtons.begin(); it != gameListButtons.end(); it++)
				{
					(*it)->noActived();
				}
				if (currentMarkedGame == gameListButtons.size() - 1)
				{
					currentMarkedGame = 0;
				}
				else
				{
					currentMarkedGame++;
				}
			}
			gameListButtons[currentMarkedGame]->Actived();


			break;
		}
	}
}
