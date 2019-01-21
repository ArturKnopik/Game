#include "Mario_GameObiect.h"
#include <iostream>

std::size_t Mario::GameObiect::uid=0;

Mario::GameObiect::GameObiect()
{
	/*
	setOldPosition(sf::Vector2f(0, 0));
	setPosition(sf::Vector2f(0, 0));
	size = sf::Vector2f(32,32);
	*/
}

Mario::GameObiect::GameObiect(const sf::Vector2f position, const sf::Vector2f size, std::shared_ptr<sf::Texture> texture)
	:texture(texture)
{
	id = uid;
	uid++;
}

int Mario::GameObiect::getId()
{
	return id;
}
