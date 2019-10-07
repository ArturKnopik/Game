#pragma once
#include <vector>
#include <memory>
#include "TibiaMapCell.h"
#include "TibiaCreature.h"
namespace TCG
{
	//class MapCell;
	class Creature;
	class MapCell;
	class World
	{

		std::vector<std::vector<std::optional<std::shared_ptr<MapCell>>>> worldCellMap;
		std::vector<std::vector<std::optional<std::shared_ptr<MapCell>>>> localWorldCellMap;
	public:
		World();
		std::pair<size_t, size_t> getMaxWordlSize();
		std::vector<std::vector<std::shared_ptr<MapCell>>> getPlayArea(sf::Vector2i pos);
		void updateWorld(const float dt);
		void draw(sf::RenderWindow& window);
		void addGameObiect(size_t x, size_t y, TGC::GameObiect* gameobj);
		void addGround(size_t x, size_t y, TGC::GameObiect* gameobj);
		void addGround(size_t x, size_t y, std::shared_ptr<TGC::GameObiect> gameobj);
		void addCreature(size_t x, size_t y, Creature* creature);
		void addCreature(size_t x, size_t y, std::shared_ptr<Creature> creature);
		std::shared_ptr<MapCell> getXYCoordinateCell(size_t x, size_t y);
	};
}


