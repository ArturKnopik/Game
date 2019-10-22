#include "TibiaMapCell.h"
#include "TibiaTGCGame.h"
TGC::MapCell::MapCell()
{
	//obiectList.reserve(10);
}

void TGC::MapCell::pushItem(std::shared_ptr<TGC::Item> obiect)
{
	if (obiectList.size() != maxSize)
	{
		obiectList.push_back(std::move(obiect));
	}
}

void TGC::MapCell::pushItem(TGC::Item* obiect)
{
	if (obiectList.size() != maxSize)
	{
		obiectList.push_back(std::make_shared<TGC::Item>(*obiect));
	}
}


void TGC::MapCell::addCreature(Creature* obiect)
{
	if (!creature) 
	{
		creature = std::shared_ptr<Creature>(obiect);
	}
}

void TGC::MapCell::addCreature(std::shared_ptr<Creature> creature)
{
	if (!this->creature)
	{
		this->creature = creature;
	}
}

void TGC::MapCell::setGround(TGC::Item* obiect)
{

		ground = std::make_shared<TGC::Item>(*obiect);
}

void TGC::MapCell::setGround(std::shared_ptr<TGC::Item> obiect)
{

		ground = std::make_optional<std::shared_ptr<TGC::Item>>();
		ground = obiect;
		return;
	
}
void TGC::MapCell::popObiect()
{
	if (obiectList.size() != 0)
	{
		obiectList.pop_back();
	}
}

void TGC::MapCell::updateMapCell(const double dt)
{
	for (const auto & it : obiectList)
	{
		it->update(dt);
	}
	if (creature)
	{
		if (creature.value()->getHealth() ==0)
		{
			auto player = TGC::Global::TGCGame::getSingleton().getPlayer();
			if (creature.value()->getID() == player->getTarget()->getID())
			{
				player->setTarget(nullptr);
			}
			creature = std::nullopt;
		}
		else
		{
			creature.value()->update(dt);
		}
	}

	if (ground)
	{
		ground.value()->update(dt);
	}

}

void TGC::MapCell::drawGround(sf::RenderWindow& window)
{
	if (ground)
	{
		ground.value()->draw(window);
	}
	
	
}

void TGC::MapCell::drawCreature(sf::RenderWindow& window)
{
	if (ground)
	{
		if (creature)
		{
			creature.value()->draw(window);
		}
	}
}

void TGC::MapCell::drawObiectList(sf::RenderWindow& window)
{
	if (ground)
	{
		if (obiectList.size() != 0)
		{
			for (const auto& it : obiectList)
			{
				it->draw(window);
			}
		}
	}
}



std::shared_ptr<TGC::Item> TGC::MapCell::getGround()
{
	if (ground)
	{
		return ground.value();
	}
	return nullptr;
}

std::shared_ptr<TGC::Creature> TGC::MapCell::getCreature()
{
	if (creature)
	{
		return creature.value();
	}
	return nullptr;;
}
