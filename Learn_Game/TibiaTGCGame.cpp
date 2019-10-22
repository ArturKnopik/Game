#include "TibiaTGCGame.h"
#include "SFML/Window/Keyboard.hpp"
#include "TibiaResoureManager.h"
#include "TibiaPlayer.h"
#include "TibiaSimpleLoader.h"
#include <memory>
#include "ResourceManager.h"
#include "TibiaFactory.h"


TGC::Global::TGCGame::TGCGame()
{
	TibiaSimpleLoader();

	auto monsterPrefabHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();

	auto monstrList = monsterPrefabHandler.getMonsterList();
	std::cout << "## Start load monster prefab, monsters loaded:" << std::endl;
	for (auto it : monstrList)
	{
		std::cout << "  "<< it.second.getName() << std::endl;;
	}
	auto itemListHandler = TGC::ResoureManager::getInstance().getXMLHandler().getItemHandler();
	auto itemList = itemListHandler.getItemList();
	std::cout << "## Start load item prefab, monsters loaded:" << std::endl;
		std::cout << "  loaded items: " << itemList.size() << std::endl;; // TODO: add getter item name
	
	std::cout << "## Wordl size: " << world.getMaxWordlSize().first << ":" << world.getMaxWordlSize().second << std::endl;
	std::cout << "## Start build map" << std::endl;
	
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			int randomNumber = generateRandomNumber<int>(0, 2);
			if (randomNumber == 0)
			{
				auto item = factory.getItem(0);
				if (item)
				{
					world.addGround(i, j, item);
				}

			}
			else if (randomNumber == 1)
			{
				auto item = factory.getItem(1);
				if (item)
				{
					world.addGround(i, j, item);
				}

			}
			else if (randomNumber == 2)
			{
				auto item = factory.getItem(2);
				if (item)
				{
					world.addGround(i, j, item);
				}
			}
		}
	}
	std::cout << "## Start addong entities" << std::endl;

	//auto rat = std::make_shared<Creature>(monsterPrefabHandler.getMonsterPrefabByName("Rat"));
	auto rat = factory.getMonster("Rat");
	auto zombie = factory.getMonster("Zombie");
	auto demon = factory.getMonster("Demon");


	player = std::make_shared<Player>();

	world.addCreature(0, 0, player);
	world.addCreature(4, 4, rat);
	world.addCreature(6, 6, zombie);
	world.addCreature(2, 2, demon);
}

TGC::Global::TGCGame & TGC::Global::TGCGame::getSingleton()
{
	static TGCGame singleton;
	return singleton;
}

void TGC::Global::TGCGame::setWindow(sf::RenderWindow& window)
{
	this->window = &window;
}

sf::RenderWindow& TGC::Global::TGCGame::getWindow()
{
	return *window;
}

void TGC::Global::TGCGame::updateWorld(const double dt, std::shared_ptr<GameObiect> player)
{
	double tempDt = dt / 1000000; // used to 
	//globalAnimationTimer.updateAnimationTime(dt); //TODO: implement to "fixed time" animation obiect require work in sync;
	resolveMoveRequest();
	world.updateWorld(tempDt);
	resolveCombat();
	updateParticle(tempDt);
}

void TGC::Global::TGCGame::draw(sf::RenderWindow & window)
{
	world.draw(*this->window);
	drawParticles(window);
}

void TGC::Global::TGCGame::addMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir)
{
	moveRequest.push_back(std::make_pair(creature, dir));
}

void TGC::Global::TGCGame::resolveMoveRequest()
{
	//TODO:: 
	for (auto & it : moveRequest)
	{
		auto obiect = it.first;
		switch (it.second)
		{
		case ENUMS::Direction::DOWN:
			if (obiect->getPosition().y < world.getMaxWordlSize().second-1 )
			{
				auto destinyCell = world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y+1);
				if (destinyCell)
				{
					if (destinyCell->getGround() && !destinyCell->getCreature() && destinyCell->getGround()->isMoveable())
 					{
						it.first->setWalkingAnimation(true, ENUMS::Direction::DOWN);
						destinyCell->addCreature(world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->getCreature());
						world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->removeCreature();
						it.first->setPosition(sf::Vector2<size_t>(obiect->getPosition().x , obiect->getPosition().y+1));
						it.first->setDirection(ENUMS::Direction::DOWN);
					}
					else
					{
						it.first->setWalkingAnimation(false, ENUMS::Direction::DOWN);
						it.first->restartWalkingTime(true);
					}
				}
				else
				{
					it.first->setWalkingAnimation(false, ENUMS::Direction::DOWN);
					it.first->restartWalkingTime(true);
				}
			}
			else
			{
				it.first->setWalkingAnimation(false, ENUMS::Direction::DOWN);
				it.first->restartWalkingTime(true);
			}
			break;
		case ENUMS::Direction::UP:
			if (obiect->getPosition().y > 0)
			{
				auto destinyCell = world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y - 1);
				if (destinyCell)
				{
					if (destinyCell->getGround() && !destinyCell->getCreature() && destinyCell->getGround()->isMoveable())
					{
						it.first->setWalkingAnimation(true, ENUMS::Direction::UP);
						destinyCell->addCreature(world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->getCreature());
						world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->removeCreature();
						it.first->setPosition(sf::Vector2<size_t>(obiect->getPosition().x, obiect->getPosition().y - 1));
						it.first->setDirection(ENUMS::Direction::UP);
					}
					else
					{
						it.first->setWalkingAnimation(false, ENUMS::Direction::UP);
						it.first->restartWalkingTime(true);
					}
				}
				else
				{
					it.first->setWalkingAnimation(false, ENUMS::Direction::UP);
					it.first->restartWalkingTime(true);
				}
			}
			else
			{
				it.first->setWalkingAnimation(false, ENUMS::Direction::UP);
				it.first->restartWalkingTime(true);
			}
			break;
		case ENUMS::Direction::LEFT:
			if (obiect->getPosition().x > 0)
			{
				auto destinyCell = world.getXYCoordinateCell(obiect->getPosition().x - 1, obiect->getPosition().y );
				if (destinyCell)
				{
					if (destinyCell->getGround() && !destinyCell->getCreature() && destinyCell->getGround()->isMoveable())
					{
						it.first->setWalkingAnimation(true, ENUMS::Direction::LEFT);
						destinyCell->addCreature(world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->getCreature());
						world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->removeCreature();
						it.first->setPosition(sf::Vector2<size_t>(obiect->getPosition().x -1, obiect->getPosition().y ));
						it.first->setDirection(ENUMS::Direction::LEFT);
					}
					else
					{
						it.first->setWalkingAnimation(false, ENUMS::Direction::LEFT);
						it.first->restartWalkingTime(true);
					}
				}
				else
				{
					it.first->setWalkingAnimation(false, ENUMS::Direction::LEFT);
					it.first->restartWalkingTime(true);
				}
			}
			else
			{
				it.first->setWalkingAnimation(false, ENUMS::Direction::LEFT);
				it.first->restartWalkingTime(true);
			}

			break;
		case TGC::ENUMS::Direction::RIGHT:
			if (obiect->getPosition().x < world.getMaxWordlSize().first-1)
			{
				auto destinyCell = world.getXYCoordinateCell(obiect->getPosition().x + 1, obiect->getPosition().y);
				if (destinyCell)
				{
					if (destinyCell->getGround() && !destinyCell->getCreature() && destinyCell->getGround()->isMoveable())
					{
						it.first->setWalkingAnimation(true, ENUMS::Direction::RIGHT);
						destinyCell->addCreature(world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->getCreature());
						world.getXYCoordinateCell(obiect->getPosition().x, obiect->getPosition().y)->removeCreature();
						it.first->setPosition(sf::Vector2<size_t>(obiect->getPosition().x + 1, obiect->getPosition().y));
						it.first->setDirection(ENUMS::Direction::RIGHT);
						
					}
					else
					{
						it.first->setWalkingAnimation(false, ENUMS::Direction::RIGHT);
						it.first->restartWalkingTime(true);
					}
				}
				else
				{
					it.first->setWalkingAnimation(false, ENUMS::Direction::RIGHT);
					it.first->restartWalkingTime(true);
				}
			}
			else
			{
				it.first->setWalkingAnimation(false, ENUMS::Direction::RIGHT);
				it.first->restartWalkingTime(true);
			}
			break;

		default:
			break;
		}

	}
	moveRequest.clear();
}

bool TGC::Global::TGCGame::isPlayerAndTargetExist(TGC::Creature* creature, std::shared_ptr<TGC::Creature> target)
{
	if (isPlayerExits(creature) && isTargetExist(target))
	{
		return true;
	}
	return false;

}

bool TGC::Global::TGCGame::isPlayerExits(TGC::Creature* creature)
{
	if (creature)
	{
		return true;
	}
	return false;
}

bool TGC::Global::TGCGame::isTargetExist(std::shared_ptr<TGC::Creature> target)
{
	if (target)
	{
		return true;
	}
	return false;
}

bool TGC::Global::TGCGame::isSameObjectUID(TGC::Creature* creature, std::shared_ptr<TGC::Creature> target)
{
	if (creature->getID() == target->getID())
	{
		return true;
	}
	return false;
}

void TGC::Global::TGCGame::resolveCombat()
{
	for (auto & it : combatRequest)
	{
		if (isPlayerAndTargetExist(it.getAttacker(), it.getTarget()))
		{
			if (!isSameObjectUID(it.getAttacker(), it.getTarget()))
			{
				double absorbValue = it.getTarget()->getAbsorbValue(it.getCombat().getType());
				double damage = it.getCombat().getValue();
				double newDamageValue = damage / (absorbValue / 100);
				//it.getTarget()->set
				it.getTarget()->removeHealth(newDamageValue);
				std::unique_ptr<Particle> partToAdd = std::make_unique<Particle>(it.getTarget()->getPosition().x, it.getTarget()->getPosition().y, "sampleParticle");
				TGC::Global::TGCGame::getSingleton().addParticle(std::move(partToAdd));
			}
		}
	}
	combatRequest.clear();
}

void TGC::Global::TGCGame::updateParticle(const double dt)
{
	auto partIter = particleList.begin();
	auto partEnd = particleList.end();
	for (auto iter = particleList.begin(); iter != particleList.end(); )
	{
		if ((*iter)->isDeath())
		{
			iter = particleList.erase(iter); // _advances_ iter, so this loop is not infinite
		}
		else
		{
			(*iter)->update(dt);
			++iter;
		}
	}
}

void TGC::Global::TGCGame::drawParticles(sf::RenderWindow& window)
{
	for (auto& partIter : particleList)
	{
		partIter->draw(window);
	}
}

void TGC::Global::TGCGame::input(sf::Event& event)
{
	player->input(*window);
}

bool TGC::Global::TGCGame::isEndAnimationTimeReached()
{
	return globalAnimationTimer.isEndAnimationTimeReached();
}

void TGC::Global::TGCGame::addCombatObiect(TGC::CombatObiect combatObj)
{
	combatRequest.push_back(combatObj);
}

std::shared_ptr<TGC::MapCell> TGC::Global::TGCGame::getXYCoordinateCell(size_t x, size_t y)
{

	return world.getXYCoordinateCell(x, y);
}

std::vector<std::vector<std::shared_ptr<TGC::MapCell>>> TGC::Global::TGCGame::getLocalArea(size_t x, size_t y)
{
	return world.getLocalArea();
}

void TGC::Global::TGCGame::addParticle(std::unique_ptr<TGC::Particle> particle)
{
	particleList.push_back(std::move(particle));
}

