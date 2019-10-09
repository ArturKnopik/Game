#include "TibiaWorld.h"

TGC::World::World()
{
	//std::vector<std::vector<std::shared_ptr<MapCell>>>>
	std::vector<std::vector<std::optional<std::shared_ptr<MapCell>>>> matrix(10, std::vector<std::optional<std::shared_ptr<MapCell>>>(10, std::optional<std::shared_ptr<MapCell>>(std::nullopt)));
	worldCellMap = matrix;
}

std::pair<size_t, size_t> TGC::World::getMaxWordlSize()
{
	return std::make_pair(worldCellMap.size(), worldCellMap[0].size());
}

std::vector<std::vector<std::shared_ptr<TGC::MapCell>>> TGC::World::getLocalArea(size_t x, size_t y)
{
	//TODO: implement getter for local area
	return std::vector<std::vector<std::shared_ptr<TGC::MapCell>>>();
}

void TGC::World::updateWorld(const double dt)
{
	for (const auto& itx : worldCellMap)
	{
		for (const auto& ity : itx)
		{

			if (ity)
			{
				ity.value()->updateMapCell(dt);
			}
		}
	}
}

void TGC::World::draw(sf::RenderWindow& window)
{
	
	for (const auto& itx : worldCellMap)
	{
		for (const auto& ity : itx)
		{
			if (ity)
			{
				ity.value()->drawGround(window);
			}
		}

	}
	for (const auto& itx : worldCellMap)
	{
		for (const auto& ity : itx)
		{
			if (ity)
			{
				ity.value()->drawObiectList(window);
			}
		}
	}
	for (const auto& itx : worldCellMap)
	{
		for (const auto& ity : itx)
		{
			if (ity)
			{
				ity.value()->drawCreature(window);
			}
		}
	}
	
}

void TGC::World::addGameObiect(size_t x, size_t y, GameObiect* gameobj)
{
	if (x < 0 || y < 0)
	{
		return;
	}
	if (getMaxWordlSize().first  < x || getMaxWordlSize().second  < y)
	{
		std::cout << "!!!can't add game obiect on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	
	if (worldCellMap[x][y])
	{
		worldCellMap[x][y].value()->pushObiect(gameobj);
	}
	
}
void TGC::World::addGround(size_t x, size_t y, GameObiect* gameobj)
{
	if (x < 0 || y < 0)
	{
		std::cout << "!!!can't add ground on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first < x || getMaxWordlSize().second < y )
	{
		std::cout << "!!!can't add ground on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (!worldCellMap[x][y])
	{
		worldCellMap[x][y] = std::shared_ptr<MapCell>();
	}
	worldCellMap[x][y].value()->setGround(gameobj);

}

void TGC::World::addGround(size_t x, size_t y, std::shared_ptr < GameObiect> gameobj)
{
	if (x < 0 || y < 0)
	{
		std::cout << "!!!can't add ground on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first < x  || getMaxWordlSize().second-1 < y )
	{
		std::cout << "!!!can't add ground on " << x << ":" << x << " coordinates!!!!" << std::endl;
		return;
	}
	if (worldCellMap[x][y])
	{
		worldCellMap[x][y].value()->setGround(gameobj);
		gameobj->setPosition(sf::Vector2<size_t>(x, y));
	}
	else
	{
		worldCellMap[x][y] = std::shared_ptr<MapCell>(new MapCell());
		gameobj->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y].value()->setGround(gameobj);

	}

}

void TGC::World::addCreature(size_t x, size_t y, Creature* creature)
{
	if (x < 0 || y < 0)
	{
		std::cout << "cant add creature on " << x << ":" << x << " coordinates!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first < x || getMaxWordlSize().second < y)
	{
		std::cout << "cant add creature on " << x << ":" << x << " coordinates!" << std::endl;
		return;
	}
	if (!creature)
	{
		return;
	}
	if (worldCellMap[x][y])
	{
		creature->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y].value()->addCreature(creature);
	}
	else
	{
		std::cout << "cant add creature on " << x << ":" << x << " coordinates!" << std::endl;
	}

}

void TGC::World::addCreature(size_t x, size_t y, std::shared_ptr<Creature> creature)
{
	if (x < 0 || y < 0)
	{
		std::cout << "cant add creature on " << x << ":" << x << " coordinates!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first <= x || getMaxWordlSize().second - 1 < y)
	{
		std::cout << "cant add creature on " << x << ":" << x << " coordinates!" << std::endl;
		return;
	}
	if (!creature)
	{
		return;
	}
	if (worldCellMap[x][y])
	{
		creature->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y].value()->addCreature(creature);
	}

}

std::shared_ptr<TGC::MapCell> TGC::World::getXYCoordinateCell(size_t x, size_t y)
{
	if (getMaxWordlSize().first-1 < x || getMaxWordlSize().first < 0 || getMaxWordlSize().second-1  < y || getMaxWordlSize().second < 0)
	{
		return nullptr;
	}

	if (worldCellMap[x][y].has_value())
	{
			return worldCellMap[x][y].value();
	}

}
