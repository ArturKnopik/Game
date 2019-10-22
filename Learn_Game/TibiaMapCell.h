#pragma once

#include <memory>
#include <vector>
#include "TibiaItem.h"
#include "TibiaCreature.h"
#include <optional>
namespace TGC
{
	class GameObiect;
	class Creature;


	class MapCell
	{
		std::size_t maxSize = 10;
		std::vector<std::shared_ptr<Item>> obiectList;
		std::optional<std::shared_ptr<Creature>> creature;
		std::optional<std::shared_ptr<Item>> ground;
	public:
		MapCell();
		//std::vector<std::unique_ptr<GameObiect>> & getObiectList() { return obiectList; };
		void pushItem(std::shared_ptr<Item> obiect);
		void pushItem(Item* obiect);
		void addCreature(Creature* obiect);
		void addCreature(std::shared_ptr<Creature> creature);
		void setGround(Item* obiect);
		void setGround(std::shared_ptr<Item> obiect);
		void removeCreature() { creature = std::nullopt; };
		void popObiect();
		void updateMapCell(const double dt);
		void drawGround(sf::RenderWindow& window);
		void drawCreature(sf::RenderWindow& window);
		void drawObiectList(sf::RenderWindow& window);
		std::shared_ptr<TGC::Item> getGround();
		std::shared_ptr<Creature> getCreature();

	};
}
