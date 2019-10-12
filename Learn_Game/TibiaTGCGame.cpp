#include "TibiaTGCGame.h"
#include "SFML/Window/Keyboard.hpp"
#include "TibiaResoureManager.h"
#include "TibiaPlayer.h"
#include "TibiaRat.h"
TGC::Global::TGCGame::TGCGame()
{
	//ResoureManager::getInstance().addResourceHandler(std::shared_ptr<ResourceHandler>(std::make_shared<TextureHandler>()));
	//std::shared_ptr<ResourceHandler> textureHandler =  ResoureManager::getInstance().getResourceHandler(std::string("texture"));
	std::cout << "wordl size: " << world.getMaxWordlSize().first << ":" << world.getMaxWordlSize().second << std::endl;
	std::cout << "start build map" << std::endl;
	player = std::make_shared<Player>();
	std::shared_ptr<GameObiect> obiect = std::make_shared<GameObiect>();
	obiect->setPosition(sf::Vector2<size_t>(0, 0));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::shared_ptr<GameObiect> obiect = std::make_shared<GameObiect>();
			obiect->setPosition(sf::Vector2<size_t>(i, j));
			world.addGround(i, j, obiect);
		}
	}
	auto rat = std::make_shared<Rat>();
	auto rat2 = std::make_shared<Rat>();
	world.addCreature(0, 0, player);
	world.addCreature(0, 1, rat2);
	world.addCreature(4, 4, rat);
	std::cout << "end build map" << std::endl;
//	rat->setTarget(player);
	player->setHealth(player->getMaxHealth());
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
}

void TGC::Global::TGCGame::draw(sf::RenderWindow & window)
{
	world.draw(*this->window);
}

void TGC::Global::TGCGame::addMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir)
{
	moveRequest.push_back(std::make_pair(creature, dir));
}

void TGC::Global::TGCGame::resolveMoveRequest()
{
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
					if (destinyCell->getGround() && !destinyCell->getCreature())
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
					if (destinyCell->getGround() && !destinyCell->getCreature())
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
					if (destinyCell->getGround() && !destinyCell->getCreature())
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
					if (destinyCell->getGround() && !destinyCell->getCreature())
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

void TGC::Global::TGCGame::resolveCombat()
{
	for (auto & it : combatRequest)
	{
		if(it.getTarget() && it.getAttacker())
		if (it.getAttacker()->getID() != it.getTarget()->getID())
		{
			double absorbValue = it.getTarget()->getAbsorbValue(it.getCombat().getType());
			double damage = it.getCombat().getValue();
			double newDamageValue = damage /(absorbValue/100); 
			//it.getTarget()->set
			it.getTarget()->removeHealth(newDamageValue);
		}
	}
	combatRequest.clear();
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

