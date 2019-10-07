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

		std::vector<std::vector<std::optional<std::shared_ptr<TGC::MapCell>>>> worldCellMap;
		std::vector<std::vector<std::optional<std::shared_ptr<TGC::MapCell>>>> localWorldCellMap;
	public:
		World();
		std::pair<size_t, size_t> getMaxWordlSize();
		std::vector<std::vector<std::shared_ptr<TGC::MapCell>>> getPlayArea(sf::Vector2i pos);
		void updateWorld(const float dt);
		void draw(sf::RenderWindow& window);
		void addGameObiect(size_t x, size_t y, TGC::GameObiect* gameobj);
		void addGround(size_t x, size_t y, TGC::GameObiect* gameobj);
		void addGround(size_t x, size_t y, std::shared_ptr<TGC::GameObiect> gameobj);
		void addCreature(size_t x, size_t y, TGC::Creature* creature);
		void addCreature(size_t x, size_t y, std::shared_ptr<TGC::Creature> creature);
		std::shared_ptr<TGC::MapCell> getXYCoordinateCell(size_t x, size_t y);
	};
}


