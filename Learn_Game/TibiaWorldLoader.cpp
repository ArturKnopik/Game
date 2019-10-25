#include "TibiaWorldLoader.h"
#include "TibiaResoureManager.h"

void TGC::WorldLoader::parseWorldNode(const pugi::xml_node& itemNode)
{
	using namespace TGC::UtilityTools;
	size_t positionX = 0;
	size_t positionY = 0;
	size_t id = 0;
	std::string usage;
	std::string monsterName;
	pugi::xml_attribute idAttribute = itemNode.attribute("id");
	pugi::xml_attribute monsterNameAttribute = itemNode.attribute("monsterName");
	if (idAttribute) {
		id = idAttribute.as_ullong();
	}
	else if (monsterNameAttribute)
	{
		monsterName = std::string(monsterNameAttribute.as_string());
	}
	else
	{
		return;
	}

	pugi::xml_attribute positionXAttribute = itemNode.attribute("positionX");
	if (positionXAttribute) {
		positionX = positionXAttribute.as_ullong();
	}
	else
	{
		return;
	}

	pugi::xml_attribute positionYAttribute = itemNode.attribute("positionY");
	if (positionYAttribute) {
		positionY = positionYAttribute.as_ullong();
	}
	else
	{
		return;
	}
	pugi::xml_attribute usageAttribute = itemNode.attribute("usage");
	if (usageAttribute) {
		usage  = std::string(usageAttribute.as_string());
	}
	else
	{
		return;
	}
	for (auto attributeNode : itemNode.children())
	{
		pugi::xml_attribute keyAttribute = attributeNode.attribute("key");
		if (!keyAttribute) {
			continue;
		}
		std::string tmpStrValue = asLowerCaseString(std::string(keyAttribute.as_string()));

		/* //TODO: implement script system like onStep, onLeaveTile etc
		if (tmpStrValue == "script")
		{
			pugi::xml_attribute valuePickableAttribute = attributeNode.attribute("value");
			if (!valuePickableAttribute) {
				continue;
			}
			auto tempValue = std::string(valuePickableAttribute.as_string());
			if (tempValue == "true" || tempValue == "false")
			{
				if (tempValue == "true")
				{
					it.setPickable(true);
				}
				else
				{
					it.setPickable(false);
				}
			}
		}
		*/
	}

	auto cell = loadedWorldPRT->getXYCoordinateCell(positionX, positionY);
	if (!cell)
	{
		loadedWorldPRT->createCell(positionX, positionY);
		cell = loadedWorldPRT->getXYCoordinateCell(positionX, positionY);
		if (!cell)
		{
			return;
		}
	}
	if (usage == "ground")
	{
		if (!cell->getGround())
		{
			auto itemHandler = TGC::ResoureManager::getInstance().getXMLHandler().getItemHandler();
			auto item = std::make_shared<Item>(itemHandler.getItemPrefabByID(id));
			item->setPosition(sf::Vector2<size_t>(positionX, positionY));
			cell->setGround(item);
		}
	}
	else if (usage == "item")
	{
		if (cell->getGround())
		{
			auto itemHandler = TGC::ResoureManager::getInstance().getXMLHandler().getItemHandler();
			auto item = std::make_shared<Item>(itemHandler.getItemPrefabByID(id));
			item->setPosition(sf::Vector2<size_t>(positionX, positionY));
			cell->pushItem(item);
		}
	}
	else if (usage == "creature")
	{
		std::cout << "creature" << std::endl;
		if (cell->getGround())
		{
			auto monsterHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();
			auto monster = std::make_shared<Creature>(monsterHandler.getMonsterByName(monsterName));
			monster->setPosition(sf::Vector2<size_t>(positionX, positionY));
			cell->addCreature(monster);
		}
	}
}

TGC::WorldLoader::WorldLoader()
{
	loadedWorldPRT = std::make_shared<World>();
}

void TGC::WorldLoader::loadFromFile()
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("./resource/XML/Tibia/world.xml");
	if (!result) {
		std::cout << "error:world.xml" << std::endl;
		return;
	}
	auto root = doc.child("world");
	size_t worldSizeX = 0;
	size_t worldSizeY = 0;
	worldSizeX = root.attribute("sizeX").as_ullong();
	worldSizeY = root.attribute("sizeY").as_ullong();
	if (worldSizeX == 0 && worldSizeY == 0)
	{
		std::cout << "error:world.xml" << std::endl;
		return;
	}

	loadedWorldPRT =  std::make_shared<World>(worldSizeX, worldSizeY);
	std::cout << loadedWorldPRT->getMaxWordlSize().first << ":" << loadedWorldPRT->getMaxWordlSize().second << std::endl;
	for (auto itemNode : doc.child("world").children())
	{
		pugi::xml_attribute positionXAttribute = itemNode.attribute("positionX");
		pugi::xml_attribute positionYAttribute = itemNode.attribute("positionY");
		pugi::xml_attribute idAttribute = itemNode.attribute("id");
		pugi::xml_attribute monsterNameAttribute = itemNode.attribute("monsterName");
		if (positionXAttribute && positionYAttribute && (idAttribute || monsterNameAttribute))
		{
			parseWorldNode(itemNode);
			continue;
		}
	}
}

std::shared_ptr<TGC::World> &  TGC::WorldLoader::getWorld()
{
	//std::cout << "new World size" << loadedWorldPRT->getMaxWordlSize().first << ":" << loadedWorldPRT->getMaxWordlSize().second << std::endl;
	return loadedWorldPRT;
}
