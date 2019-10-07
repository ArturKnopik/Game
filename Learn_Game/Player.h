#pragma once
#include "TibiaCreature.h"
#include "SFML/Graphics/Texture.hpp"
namespace TCG
{
	class Player :
		public TGC::Creature
	{
	private:
	public:
		Player();
		const sf::Vector2<size_t> getSpritePosition() const;
		void input();


		virtual void renderDebug(sf::RenderWindow& renderWindow) override
		{

			sf::RectangleShape rect;
			switch (*getDirection())
			{
			case TGC::ENUMS::Direction::UP:
				rect.setFillColor(sf::Color(255, 0, 0, 80));
				break;
			case TGC::ENUMS::Direction::DOWN:
				rect.setFillColor(sf::Color(0, 255, 0, 80));
				break;
			case TGC::ENUMS::Direction::LEFT:
				rect.setFillColor(sf::Color(0, 0, 255, 80));
				break;
			case TGC::ENUMS::Direction::RIGHT:
				rect.setFillColor(sf::Color(100, 100, 100, 80));

				break;
			}
			rect.setPosition(sf::Vector2f(static_cast<float>(position.x * 32 + 2), static_cast<float>(position.y * 32 + 2)));
			rect.setSize(sf::Vector2f(28, 28));
			renderWindow.draw(rect);
			Creature::draw(renderWindow);
		}
	};
}
