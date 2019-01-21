#include "Mario_Player.h"
#include <iostream>
#include "SFML/Window/Event.hpp"
#include "ResourceManager.h"
Mario::Player::Player(const sf::Vector2f position, const sf::Vector2f size, std::shared_ptr<sf::Texture> texture)
	:GameObiect(position, size, texture)
{
	//siteOfAnimation = Mario::SiteOfAnimation::JUMP_LEFT;
}

void Mario::Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
	
	//window->draw(getSprite());
	//window->draw(*(animatedSprite.getAnimation()->getSprite()));
}

void Mario::Player::update(const float dt)
{
	std::cout << "Update" << std::endl;

}

void Mario::Player::input(std::shared_ptr<sf::Event> event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
	}
	else
	{

	}

}


