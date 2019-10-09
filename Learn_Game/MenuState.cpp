#include "MenuState.h"
#include "GameListState.h"
#include "ResourceManager.h"

MenuState::MenuState(std::shared_ptr<Game> game) {
	this->game = game;
	game->window->setView(game->window->getDefaultView());
	font.loadFromFile("resource/font/arial.ttf");
	menuButtonElements.push_back(std::unique_ptr<Button>(new BasicButton("List of games", sf::Vector2f(100,100), sf::Vector2f(600, 50), 50, sf::Color(0,100,200,150), sf::Color(255, 0, 0, 180))));
	menuButtonElements.push_back(std::unique_ptr<Button>(new BasicButton("About", sf::Vector2f(100, 200), sf::Vector2f(600, 50), 50, sf::Color(0, 0, 255, 150), sf::Color(0, 255, 0, 200))));
	menuButtonElements.push_back(std::unique_ptr<Button>(new BasicButton("Quit", 100, 300, 600, 50, 50, sf::Color(0, 100, 155, 200), sf::Color::Red)));
}


void MenuState::input() {


	while (game->window->pollEvent(event)) {
		switch (event.type) {
			/* Close the window */
		case sf::Event::Closed:
			game->window->close();
			break;

			/* Change Between game states */
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				game->window->close();
			}
			if (event.key.code == sf::Keyboard::Return && menuSwitch == 0) {
				loadGameMenu();
			}
			if (event.key.code == sf::Keyboard::Return && menuSwitch == 1) {
				std::cout << "About" << std::endl;
			}
			if (event.key.code == sf::Keyboard::Return && menuSwitch == 2) {
				game->window->close();
			}

			if (event.key.code == sf::Keyboard::Up) {
				if (menuSwitch >= 1) {
					menuSwitch--;
				}
				else {
					menuSwitch = 2;
				}
			}

			if (event.key.code == sf::Keyboard::Down) {
				if (menuSwitch <= 1) {
					menuSwitch++;
				}
				else {
					menuSwitch = 0;
				}
			}
			break;
		}
	}
}

void MenuState::update(const double dt) {

	switch (menuSwitch) {
	case 0:
		for (int i = 0; i < menuButtonElements.size(); i++) {
			if (i == menuSwitch) {
				menuButtonElements[i]->Actived();
			}
			else {
				menuButtonElements[i]->noActived();
			}
		}

		break;
	case 1:
		for (int i = 0; i < menuButtonElements.size(); i++) {
			if (i == menuSwitch) {
				menuButtonElements[i]->Actived();
			}
			else {
				menuButtonElements[i]->noActived();
			}
		}
		break;
	case 2:
		for (int i = 0; i < menuButtonElements.size(); i++) {
			if (i == menuSwitch) {
				menuButtonElements[i]->Actived();
			}
			else {
				menuButtonElements[i]->noActived();
			}
		}
		break;
	}
}

void MenuState::draw() 
{
	for (int i = 0; i < menuButtonElements.size(); i++) {
		menuButtonElements[i]->draw(game->window);
	}
}


void MenuState::loadGameMenu()
{
	game->pushState(std::shared_ptr<GameState>(new GameListState(game)));
}
