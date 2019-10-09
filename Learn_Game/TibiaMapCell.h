#pragma once

#include <memory>
#include <vector>
#include "TibiaGameObiect.h"
#include "TibiaCreature.h"
#include <optional>
namespace TGC
{
	class GameObiect;
	class Creature;


	class MapCell
	{
		std::size_t maxSize = 10;
		std::vector<std::shared_ptr<GameObiect>> obiectList;
		std::optional<std::shared_ptr<Creature>> creature;
		std::optional<std::shared_ptr<GameObiect>> ground;
	public:
		MapCell();
		//std::vector<std::unique_ptr<GameObiect>> & getObiectList() { return obiectList; };
		void pushObiect(std::shared_ptr<GameObiect> obiect);
		void pushObiect(GameObiect* obiect);
		void addCreature(Creature* obiect);
		void addCreature(std::shared_ptr<Creature> creature);
		void setGround(GameObiect* obiect);
		void setGround(std::shared_ptr<GameObiect> obiect);
		void removeCreature() { creature = std::nullopt; };
		void popObiect();
		void updateMapCell(const double dt);
		void drawGround(sf::RenderWindow& window);
		void drawCreature(sf::RenderWindow& window);
		void drawObiectList(sf::RenderWindow& window);
		std::shared_ptr<GameObiect> getGround();
		std::shared_ptr<Creature> getCreature();

	};
}
