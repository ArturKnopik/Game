#pragma once
#include "TibiaCreature.h"
#include "SFML/Graphics/Texture.hpp"
namespace TGC
{
	class Player :
		public TGC::Creature
	{
	private:
		std::pair<double, double> useThingTimer = std::make_pair(0, Setting::Const::timeToUseThings); // first current time, second maxTime
	public:
		Player();
		const sf::Vector2<size_t> getSpritePosition() const;
		void drawCurrentCellMarkRectangle(sf::RenderWindow& renderWindow);
		void drawCurrentTargetMarkRectangle(sf::RenderWindow& renderWindow);
		void input(sf::RenderWindow& renderWindow);
		void doThingWithTargetCell();
		void updateUseThingTimer(const double dt);
		void restartUseTimer();
		bool canUseThing();
		virtual void update(const double dt) override;
		virtual void draw(sf::RenderWindow& renderWindow) override;
	};

}