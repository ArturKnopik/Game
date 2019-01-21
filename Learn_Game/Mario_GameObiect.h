#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "Timer.h"
#include "CollisionChecker.h"

namespace Mario
{

	/*
	GameObiect Class
	Abstract class represent all of game obiects
	*/

	class GameObiect
	{
	private:
		std::size_t id;
		static std::size_t uid;
		std::shared_ptr<sf::Texture> texture;

	protected:
		//SiteOfAnimation siteOfAnimation;
	public:
		// Default c-tor
		GameObiect();

		// Custom c-tor
		GameObiect(const sf::Vector2f position, const sf::Vector2f size, std::shared_ptr<sf::Texture> texture);

		// Virtual dc-tor
		virtual ~GameObiect()=default;

		// return id of this obiect
		int getId();

		// obiect drawing method
		virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;

		// obiect update method
		virtual void update(const float dt) = 0;
	};
}

