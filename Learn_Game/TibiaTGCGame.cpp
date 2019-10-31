#include "TibiaTGCGame.h"
#include "SFML/Window/Keyboard.hpp"
#include "TibiaResoureManager.h"
#include "TibiaPlayer.h"
#include "TibiaSimpleLoader.h"
#include <memory>
#include "ResourceManager.h"
#include "TibiaFactory.h"
#include "TibiaSpawnScript.h"

TGC::Global::TGCGame::TGCGame()
{
	worldPRT = std::make_shared<TGC::World>();
	auto monsterPrefabHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();

	auto monstrList = monsterPrefabHandler.getMonsterList();
	std::cout << "## Start load monster prefab, monsters loaded:" << std::endl;
	for (auto it : monstrList)
	{
		std::cout << "  " << it.second.getName()<<"    ";
	}
	std::cout << std::endl;
	auto itemListHandler = TGC::ResoureManager::getInstance().getXMLHandler().getItemHandler();
	auto itemList = itemListHandler.getItemList();
	std::cout << "## Start load item prefab, item loaded:" << std::endl;
	std::cout << "  loaded items: " << itemList.size() << std::endl;; 
	std::cout << "## Start build map" << std::endl;
	auto worldHandler = TGC::ResoureManager::getInstance().getXMLHandler().getWorldLoader();
	worldHandler.loadFromFile();
	worldPRT=worldHandler.getWorld();
	std::cout << "## Wordl size: " << worldPRT->getMaxWordlSize().first << ":" << worldPRT->getMaxWordlSize().second << std::endl;
	std::cout << "## Adding player " << std::endl;
	player = std::make_shared<Player>();
	worldPRT->addCreature(7, 7, player);
	
	/*
	auto item = std::make_shared<TGC::Item>(itemListHandler.getItemPrefabByID(4));
	item->addScript(std::make_shared<TGC::TeleportScript>(2, 2,));
	item->setPosition(sf::Vector2<size_t>(9, 9));
	worldPRT->addGameobject(9, 9, item);
	*/
	
}

TGC::Global::TGCGame& TGC::Global::TGCGame::getSingleton()
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

void TGC::Global::TGCGame::updateWorld(const double dt, std::shared_ptr<Gameobject> player)
{
	double tempDt = dt / 1000000; // used to 
	//globalAnimationTimer.updateAnimationTime(dt); //TODO: implement to "fixed time" animation object require work in sync;
	resolveMoveRequest();
	worldPRT->updateWorld(tempDt);
	resolveCombat();
	updateParticle(tempDt);
}

void TGC::Global::TGCGame::draw(sf::RenderWindow& window)
{
	worldPRT->draw(*this->window);
	drawParticles(window);
}

void TGC::Global::TGCGame::addMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir)
{
	moveRequest.push_back(std::make_pair(creature, dir));
}

bool TGC::Global::TGCGame::checkIfCellIsPossibleToMakeAMove(std::shared_ptr<TGC::MapCell> destinyCell)
{
	if (destinyCell && destinyCell->getGround() && !destinyCell->getCreature() && destinyCell->getGround()->isMoveable())
	{
		bool itemStackMoveableStatus = true;
		auto itemSt = destinyCell->getItemStack();
		for (auto it : itemSt)
		{
			if (!it->isMoveable())
			{
				itemStackMoveableStatus = false;
			}
			
		}
		if (itemStackMoveableStatus)
		{
			return true;
		}
		
	}
	return false;
}



void TGC::Global::TGCGame::ResolveSingleMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir)
{
	//TODO: this method is to big, find way to reduce it size
	switch (dir)
	{
	case ENUMS::Direction::DOWN:
		if (creature->getPosition().y < worldPRT->getMaxWordlSize().second - 1)
		{
			auto destinyCell = worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y + 1);
			if (checkIfCellIsPossibleToMakeAMove(destinyCell))
			{
				creature->setWalkingAnimation(true, ENUMS::Direction::DOWN);
				destinyCell->addCreature(worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->getCreature());
				worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->removeCreature();
				creature->setPosition(sf::Vector2<size_t>(creature->getPosition().x, creature->getPosition().y + 1));
				creature->setDirection(ENUMS::Direction::DOWN);
			}
			else
			{
				creature->setWalkingAnimation(false, ENUMS::Direction::DOWN);
				creature->restartWalkingTime(true);
			}
		}
		else
		{
			creature->setWalkingAnimation(false, ENUMS::Direction::DOWN);
			creature->restartWalkingTime(true);
		}
		break;
	case ENUMS::Direction::UP:
		if (creature->getPosition().y > 0)
		{
			auto destinyCell = worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y - 1);
			if (checkIfCellIsPossibleToMakeAMove(destinyCell))
			{
				creature->setWalkingAnimation(true, ENUMS::Direction::UP);
				destinyCell->addCreature(worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->getCreature());
				worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->removeCreature();
				creature->setPosition(sf::Vector2<size_t>(creature->getPosition().x, creature->getPosition().y - 1));
				creature->setDirection(ENUMS::Direction::UP);
			}
			else
			{
				creature->setWalkingAnimation(false, ENUMS::Direction::UP);
				creature->restartWalkingTime(true);
			}
		}
		else
		{
			creature->setWalkingAnimation(false, ENUMS::Direction::UP);
			creature->restartWalkingTime(true);
		}
		break;
	case ENUMS::Direction::LEFT:
		if (creature->getPosition().x > 0)
		{
			auto destinyCell = worldPRT->getXYCoordinateCell(creature->getPosition().x - 1, creature->getPosition().y);
			if (checkIfCellIsPossibleToMakeAMove(destinyCell))
			{
				creature->setWalkingAnimation(true, ENUMS::Direction::LEFT);
				destinyCell->addCreature(worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->getCreature());
				worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->removeCreature();
				creature->setPosition(sf::Vector2<size_t>(creature->getPosition().x - 1, creature->getPosition().y));
				creature->setDirection(ENUMS::Direction::LEFT);
			}
			else
			{
				creature->setWalkingAnimation(false, ENUMS::Direction::LEFT);
				creature->restartWalkingTime(true);
			}
		}
		else
		{
			creature->setWalkingAnimation(false, ENUMS::Direction::LEFT);
			creature->restartWalkingTime(true);
		}
		break;
	case TGC::ENUMS::Direction::RIGHT:
		if (creature->getPosition().x < worldPRT->getMaxWordlSize().first - 1)
		{
			auto destinyCell = worldPRT->getXYCoordinateCell(creature->getPosition().x + 1, creature->getPosition().y);
			if (checkIfCellIsPossibleToMakeAMove(destinyCell))
			{
				creature->setWalkingAnimation(true, ENUMS::Direction::RIGHT);
				destinyCell->addCreature(worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->getCreature());
				worldPRT->getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y)->removeCreature();
				creature->setPosition(sf::Vector2<size_t>(creature->getPosition().x + 1, creature->getPosition().y));
				creature->setDirection(ENUMS::Direction::RIGHT);
				executeMoveScripts(creature, destinyCell);

			}
			else
			{
				creature->setWalkingAnimation(false, ENUMS::Direction::RIGHT);
				creature->restartWalkingTime(true);
			}
		}
		else
		{
			creature->setWalkingAnimation(false, ENUMS::Direction::RIGHT);
			creature->restartWalkingTime(true);
		}
		break;

	default:
		break;
	}

}

void TGC::Global::TGCGame::executeMoveScripts(Creature* creature, std::shared_ptr<TGC::MapCell> targetMapCell)
{
	for (auto it : targetMapCell->getItemStack())
	{
		for (auto iter : it->getScripts())
		{
			if (iter->getTrigerType() == TGC::ENUMS::ScriptTrigerType::ONSTEP)
			{
				iter->executeScript(creature);
				if (iter->isSingleExecute())
				{
					//TODO: implemet remove Script
				}
			}
		}
	}
}


void TGC::Global::TGCGame::resolveMoveRequest()
{
	for (auto& it : moveRequest)
	{
		auto object = it.first;
		ResolveSingleMoveRequest(object, it.second);
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
	for (auto& it : combatRequest)
	{
		if (isPlayerAndTargetExist(it.getAttacker(), it.getTarget()))
		{
			if (!isSameObjectUID(it.getAttacker(), it.getTarget()))
			{
				double absorbValue = it.getTarget()->getAbsorbValue(it.getCombat().getType());
				double damage = it.getCombat().getValue();
				double newDamageValue = damage / (absorbValue / 100);
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
			iter = particleList.erase(iter);
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

void TGC::Global::TGCGame::addCombatobject(TGC::Combatobject combatObj)
{
	combatRequest.push_back(combatObj);
}

std::shared_ptr<TGC::MapCell> TGC::Global::TGCGame::getXYCoordinateCell(size_t x, size_t y)
{

	return worldPRT->getXYCoordinateCell(x, y);
}

std::vector<std::vector<std::shared_ptr<TGC::MapCell>>> TGC::Global::TGCGame::getLocalArea(size_t x, size_t y)
{
	return worldPRT->getLocalArea();
}

void TGC::Global::TGCGame::addParticle(std::unique_ptr<TGC::Particle> particle)
{
	particleList.push_back(std::move(particle));
}

