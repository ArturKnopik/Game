#pragma once
#include "Mario_GameObiect.h"
namespace Mario
{

	class Player : public Mario::GameObiect
	{
	public:
		Player()=delete;
		~Player()=default;
		Player(const sf::Vector2f position, const sf::Vector2f size, std::shared_ptr<sf::Texture> texture);
		void draw(std::shared_ptr<sf::RenderWindow> window);
		void update(const float dt);
		void input(std::shared_ptr<sf::Event> event);
	};
}

