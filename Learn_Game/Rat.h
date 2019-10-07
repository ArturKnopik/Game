#pragma once
#include "TibiaCreature.h"
namespace TCG
{
	class Rat :
		public Creature
	{
	public:
		Rat();
		virtual void update(const float dt) override;
		virtual void renderDebug(sf::RenderWindow& renderWindow) override
		{
			sf::RectangleShape rect;
			rect.setFillColor(sf::Color(255, 0, 0, 80));
			rect.setPosition(sf::Vector2f(static_cast<float>(position.x * 32 + 2), static_cast<float>(position.y * 32 + 2)));
			rect.setSize(sf::Vector2f(28, 28));
			renderWindow.draw(rect);
			Creature::draw(renderWindow);
		}
	};
}

