#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "TibiaUtilityTools.h"
#include <iostream>
#include "SFML/Graphics/Sprite.hpp"
#include "TibiaAnimationController.h"
#include <optional>
#include "SFML/Graphics/Sprite.hpp"
namespace TGC
{
	class GameObiect
	{
	private:

	protected:
		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
		std::optional<TGC::AnimationController> animationControler;
		sf::Vector2<std::size_t> positionSprite;
		sf::Vector2<std::size_t> position;
		std::size_t uid;
	public:
		GameObiect();
		//GameObiect(const GameObiect &) = default;
		virtual void update(const double dt);
		sf::Vector2<std::size_t> getPosition() const;
		void setPosition(sf::Vector2<std::size_t> newPosition);
		std::size_t getID();
		void setTexture(std::shared_ptr<sf::Texture> texture);
		virtual void draw(sf::RenderWindow& renderWindow);
		//const sf::Sprite& getSprite() const;
		//sf::Sprite & getSprite();
		//TODO: Remove this function when create normal obiect
		virtual void renderDebug(sf::RenderWindow& renderWindow);
	};
}
