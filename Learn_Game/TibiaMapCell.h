#pragma once

#include <memory>
#include <vector>
#include "TibiaItem.h"
#include "TibiaCreature.h"
#include <optional>
namespace TGC
{
	class Gameobject;
	class Creature;


	class MapCell
	{
		std::size_t maxSize = 10;
		std::vector<std::shared_ptr<Item>> objectList;
		std::shared_ptr<Creature> creature;
		std::shared_ptr<Item> ground;
	public:
		MapCell();
		//std::vector<std::unique_ptr<Gameobject>> & getobjectList() { return objectList; };
		void pushItem(std::shared_ptr<Item> object);
		void pushItem(Item* object);
		void addCreature(Creature* object);
		void addCreature(std::shared_ptr<Creature> creature);
		void setGround(Item* object);
		void setGround(std::shared_ptr<Item> object);
		void removeCreature() { creature = nullptr; }
		void popobject();
		void updateMapCell(const double dt);
		void drawGround(sf::RenderWindow& window);
		void drawCreature(sf::RenderWindow& window);
		void drawobjectList(sf::RenderWindow& window);
		std::vector<std::shared_ptr<Item>>& getItemStack();
		std::shared_ptr<TGC::Item> getGround();
		std::shared_ptr<Creature> getCreature();

	};
}
