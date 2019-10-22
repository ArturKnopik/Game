#include "TibiaWorld.h"
#include "TibiaTGCGame.h"
TGC::World::World()
{
	//std::vector<std::vector<std::shared_ptr<MapCell>>>>
	std::vector<std::vector<std::shared_ptr<MapCell>>> matrix(50, std::vector<std::shared_ptr<MapCell>>(50, std::shared_ptr<MapCell>()));
	worldCellMap = matrix;
}

std::pair<size_t, size_t> TGC::World::getMaxWordlSize()
{
	return std::make_pair(worldCellMap.size(), worldCellMap[0].size());
}

std::vector<std::vector<std::shared_ptr<TGC::MapCell>>> TGC::World::getLocalArea()
{
	std::pair<size_t, size_t> getVieweX(11, 11);    // first left, second right
	std::pair<size_t, size_t> getVieweY(11, 11);    // first up, second down
	std::pair<size_t, size_t> matrixXRange(0, 0);    // first left, second right
	std::pair<size_t, size_t> matrixYRange(0, 0);   // first up, second down

	auto playerPos = TGC::Global::TGCGame::getSingleton().getPlayer()->getPosition();

	if (playerPos.x < getVieweX.first)
	{
		matrixXRange.first = 0;
	}
	else
	{
		matrixXRange.first = playerPos.x - getVieweX.first;
	}

	if (playerPos.x + getVieweX.second > this->getMaxWordlSize().first-1)
	{
		matrixXRange.second = getMaxWordlSize().first-1;
	}
	else
	{
		matrixXRange.second = playerPos.x + getVieweX.second;
	}

	if (playerPos.y < getVieweY.first)
	{
		matrixYRange.first = 0;
	}
	else
	{
		matrixYRange.first = playerPos.y - getVieweY.second;
	}


	if (playerPos.y + getVieweY.second > this->getMaxWordlSize().second - 1)
	{
		matrixYRange.second = getMaxWordlSize().second - 1;
	}
	else
	{
		matrixYRange.second = playerPos.y + getVieweY.second;
	}
	
	auto localMap = std::vector<std::vector<std::shared_ptr<MapCell>>>();
	localMap.clear();
	for (int i = 0; i <= matrixXRange.first + matrixXRange.second; i++)
	{
		localMap.push_back(std::vector<std::shared_ptr<MapCell>>());

		for (int j = 0; j <= matrixYRange.second + matrixYRange.second; j++)
		{
			localMap[i].push_back(std::shared_ptr<MapCell>());
		}
	}

	for (int i =0; i <= matrixXRange.second - matrixXRange.first; i++)
	{
		for (int j =0;  j <= matrixYRange.second - matrixYRange.first; j++)
		{
			localMap[i][j] = worldCellMap[i + matrixXRange.first][j + matrixYRange.first];
		}

	}
	//localWorldCellMap.clear();
	//localWorldCellMap = localMap;
	return localMap;
}

void TGC::World::updateWorld(const double dt)
{
	localWorldCellMap.clear();
	localWorldCellMap = getLocalArea();
	for (const auto & itx : localWorldCellMap) //worldCellMap
	{
		for (const auto & ity : itx)
		{

			if (ity)
			{
				ity->updateMapCell(dt);
			}
		}
	}
}

void TGC::World::draw(sf::RenderWindow& window)
{
	for (const auto & itx : localWorldCellMap)
	{
		for (const auto & ity : itx)
		{
			if (ity)
			{
				ity->drawGround(window);
			}
		}
	}
	for (const auto & itx : localWorldCellMap)
	{
		for (const auto & ity : itx)
		{
			if (ity)
			{
				ity->drawObiectList(window);
			}
		}
	}
	for (const auto & itx : localWorldCellMap)
	{
		for (const auto & ity : itx)
		{
			if (ity)
			{
				ity->drawCreature(window);
			}
		}
	}
	
}

void TGC::World::addGameObiect(size_t x, size_t y, TGC::Item* gameobj)
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
		worldCellMap[x][y]->pushItem(gameobj);
	}
	
}
void TGC::World::addGround(size_t x, size_t y, TGC::Item* gameobj)
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
	worldCellMap[x][y]->setGround(gameobj);

}

void TGC::World::addGround(size_t x, size_t y, std::shared_ptr <TGC::Item> gameobj)
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
		worldCellMap[x][y]->setGround(gameobj);
		gameobj->setPosition(sf::Vector2<size_t>(x, y));
	}
	else
	{
		worldCellMap[x][y] = std::shared_ptr<MapCell>(new MapCell());
		gameobj->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y]->setGround(gameobj);

	}

}

void TGC::World::addCreature(size_t x, size_t y, Creature* creature)
{
	if (x < 0 || y < 0)
	{
		std::cout << "!!!cant add creature on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first < x || getMaxWordlSize().second < y)
	{
		std::cout << "!!!cant add creature on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (!creature)
	{
		return;
	}
	if (worldCellMap[x][y])
	{
		creature->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y]->addCreature(creature);
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
		std::cout << "!!!cant add creature on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (getMaxWordlSize().first <= x || getMaxWordlSize().second - 1 < y)
	{
		std::cout << "!!!cant add creature on " << x << ":" << x << " coordinates!!!" << std::endl;
		return;
	}
	if (!creature)
	{
		return;
	}
	if (worldCellMap[x][y])
	{
		creature->setPosition(sf::Vector2<size_t>(x, y));
		worldCellMap[x][y]->addCreature(creature);
	}

}

std::shared_ptr<TGC::MapCell> TGC::World::getXYCoordinateCell(size_t x, size_t y)
{
	if (getMaxWordlSize().first-1 < x || getMaxWordlSize().first < 0 || getMaxWordlSize().second-1  < y || getMaxWordlSize().second < 0)
	{
		return nullptr;
	}

	if (worldCellMap[x][y])
	{
			return worldCellMap[x][y];
	}
	return nullptr;
}
