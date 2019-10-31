#include "TibiaMapCell.h"
#include "TibiaTGCGame.h"
TGC::MapCell::MapCell()
{
	//objectList.reserve(10);
}

void TGC::MapCell::pushItem(std::shared_ptr<TGC::Item> object)
{
	if (objectList.size() != maxSize)
	{
		objectList.push_back(std::move(object));
	}
}

void TGC::MapCell::pushItem(TGC::Item* object)
{
	if (objectList.size() != maxSize)
	{
		objectList.push_back(std::make_shared<TGC::Item>(*object));
	}
}


void TGC::MapCell::addCreature(Creature* object)
{
	if (!creature) 
	{
		creature = std::shared_ptr<Creature>(object);
	}
}

void TGC::MapCell::addCreature(std::shared_ptr<Creature> creature)
{
	if (!this->creature)
	{
		this->creature = creature;
	}
}

void TGC::MapCell::setGround(TGC::Item* object)
{

		ground = std::make_shared<TGC::Item>(*object);
}

void TGC::MapCell::setGround(std::shared_ptr<TGC::Item> object)
{
		ground = object;
		return;
}
void TGC::MapCell::popobject()
{
	if (objectList.size() != 0)
	{
		objectList.pop_back();
	}
}

void TGC::MapCell::updateMapCell(const double dt)
{
	for (const auto & it : objectList)
	{
		it->update(dt);
	}
	if (creature)
	{
		if (creature->getHealth() ==0)
		{
			auto player = TGC::Global::TGCGame::getSingleton().getPlayer();
			if (creature->getID() == player->getTarget()->getID())
			{
				player->setTarget(nullptr);
			}
			creature = nullptr;
		}
		else
		{
			creature->update(dt);
		}
	}

	if (ground)
	{
		ground->update(dt);
	}

}

void TGC::MapCell::drawGround(sf::RenderWindow& window)
{
	if (ground)
	{
		ground->draw(window);
	}
	
	
}

void TGC::MapCell::drawCreature(sf::RenderWindow& window)
{
	if (ground)
	{
		if (creature)
		{
			creature->draw(window);
		}
	}
}

void TGC::MapCell::drawobjectList(sf::RenderWindow& window)
{
	if (ground)
	{
		if (objectList.size() != 0)
		{
			for (const auto& it : objectList)
			{
				it->draw(window);
			}
		}
	}
}

std::vector<std::shared_ptr<TGC::Item>>& TGC::MapCell::getItemStack()
{
	return objectList;
}



std::shared_ptr<TGC::Item> TGC::MapCell::getGround()
{
	if (ground)
	{
		return ground;
	}
	return nullptr;
}

std::shared_ptr<TGC::Creature> TGC::MapCell::getCreature()
{
	if (creature)
	{
		return creature;
	}
	return nullptr;
}
