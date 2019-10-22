#pragma once
#include <vector>
#include <memory>
#include "TibiaMapCell.h"
#include "TibiaCreature.h"
namespace TGC
{
	//class MapCell;
	class Creature;
	class MapCell;
	class World
	{

		std::vector<std::vector<std::shared_ptr<MapCell>>> worldCellMap;
		std::vector<std::vector<std::shared_ptr<MapCell>>> localWorldCellMap;
	public:
		World();
		std::pair<size_t, size_t> getMaxWordlSize();
		std::vector<std::vector<std::shared_ptr<MapCell>>> getLocalArea();
		void updateWorld(const double dt);
		void draw(sf::RenderWindow& window);
		void addGameObiect(size_t x, size_t y, TGC::Item* item);
		void addGround(size_t x, size_t y, TGC::Item* item);
		void addGround(size_t x, size_t y, std::shared_ptr<TGC::Item> item);
		void addCreature(size_t x, size_t y, TGC::Creature* creature);
		void addCreature(size_t x, size_t y, std::shared_ptr<TGC::Creature> creature);
		std::shared_ptr<TGC::MapCell> getXYCoordinateCell(size_t x, size_t y);
	};
}


