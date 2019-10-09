#include "MarioGameState.h"
#include "ResourceManager.h"
#include <iostream>
#include "SFML/Window/Mouse.hpp"
#include "Mario_GumbaGameObiect.h"
#include <Windows.h>

MarioGameState::MarioGameState(std::shared_ptr<Game> game)
{
	this->game = game;
	
	//brick = std::make_shared<Brick>(sf::Vector2f(100, 500), sf::Vector2f(32, 32));
	
// LOAD RESOURCES
	std::shared_ptr<sf::Texture> marioTexture = std::make_shared<sf::Texture>();
	marioTexture->loadFromFile("resource/image/Mario/Marioimages.png");

	System::ResourceManager::getInstance().addResource(marioTexture, "Mario");

	std::shared_ptr<sf::Texture> brickTexture = std::make_shared<sf::Texture>();
	brickTexture->loadFromFile("resource/image/Mario/brick.png");
	System::ResourceManager::getInstance().addResource(brickTexture, "Brick");

	std::shared_ptr<sf::Texture> goombaTexture = std::make_shared<sf::Texture>();
	goombaTexture->loadFromFile("resource/image/Mario/goomba.png");
	System::ResourceManager::getInstance().addResource(goombaTexture, "Goomba");

	//levelControler.loadLevel("level.txt", "testLevel");
	level = levelControler.getLevel("testLevel");
	player = std::make_shared<Mario::MarioGameObiect>(sf::Vector2f(32, 32), sf::Vector2f(32, 32));
	level->addGameObiect(Mario::LevelLayer::MAIN_LAYER, player);
	

	std::cout << level->getObiectList(Mario::LevelLayer::MAIN_LAYER).size() << std::endl;;
	
	std::cout << "Player id: "; std::cout << player->getID(); std::cout << std::endl;
}

void MarioGameState::draw()
{
	sf::Sprite sprite(*System::ResourceManager::getInstance().getTexture("Mario"), sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(500, 500);
	game->window->draw(sprite);
	//player->draw(game->window);
	std::vector<std::shared_ptr<Mario::GameObiect>>::iterator it;
	for(it = level->getObiectList(Mario::LevelLayer::MAIN_LAYER).begin(); it != level->getObiectList(Mario::LevelLayer::MAIN_LAYER).end(); it++)
	{
		(*it)->draw(game->window);
	}
	
	//brick->draw(game->window);	
}

void MarioGameState::update(const double dt)
{
	//player->update(dt);
	std::vector<std::shared_ptr<Mario::GameObiect>>::iterator obiectThatCheckIt;
	std::vector<std::shared_ptr<Mario::GameObiect>>::iterator obiectCheckedIt;
	//player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + 0.0001*dt));
	for (obiectThatCheckIt = level->getObiectList(Mario::LevelLayer::MAIN_LAYER).begin(); obiectThatCheckIt != level->getObiectList(Mario::LevelLayer::MAIN_LAYER).end(); obiectThatCheckIt++)
	{
		(*obiectThatCheckIt)->update(dt);
		for (obiectCheckedIt = level->getObiectList(Mario::LevelLayer::MAIN_LAYER).begin(); obiectCheckedIt != level->getObiectList(Mario::LevelLayer::MAIN_LAYER).end(); obiectCheckedIt++)
		{
			if ((*obiectThatCheckIt)->getID() != (*obiectCheckedIt)->getID())
			{
				
				if (System::checkAABB(*obiectThatCheckIt, *obiectCheckedIt))
				{
					(*obiectThatCheckIt)->onCollision(*obiectCheckedIt);
					(*obiectCheckedIt)->onCollision(*obiectThatCheckIt);
				}
				else
				{
					if (!(*obiectThatCheckIt)->getStatic())
					{
						(*obiectThatCheckIt)->setPosition(sf::Vector2f((*obiectThatCheckIt)->getPosition().x, (*obiectThatCheckIt)->getPosition().y + 0.0005*dt));

						break;
					}

				}
			}
			
		}
		
	}
}

void MarioGameState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game->window->close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		player->setPosition(sf::Vector2f(32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		level->addGameObiect(Mario::LevelLayer::MAIN_LAYER, std::make_shared<Mario::GumbaGameObiect>(sf::Vector2f(160, 50), sf::Vector2f(32, 32)));
		Sleep(30);
	}
}


MarioGameState::~MarioGameState()
{
}
