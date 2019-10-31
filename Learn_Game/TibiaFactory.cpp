#include "TibiaFactory.h"
#include "TibiaResoureManager.h"
#include "TibiaCreature.h"
#include "TibiaParticle.h"
#include "TibiaItem.h"

TGC::Factory::Factory()
{
}

std::shared_ptr<TGC::Creature> TGC::Factory::getMonster(std::string monsterName)
{

	auto monsterHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();
	auto monsterPrefab = monsterHandler.getMonsterByName(monsterName);
	if (monsterPrefab.texture.empty() && monsterPrefab.name.empty())
	{
		std::cout << "cant create monster, prefab object not found!" << std::endl;
		return nullptr;
	}
	auto textureHandler = TGC::ResoureManager::getInstance().getTextureHandler();
	auto texture = textureHandler.getResourceByName(monsterPrefab.texture, "creature");
	if (!texture)
	{
		std::cout << "cant create monster, texture not found!" << std::endl;
		return nullptr;
	}
	return std::make_shared<TGC::Creature>(monsterPrefab);
}

std::shared_ptr<TGC::Particle> TGC::Factory::getParticle(std::string particleTexture)
{
	auto textureHandler = TGC::ResoureManager::getInstance().getTextureHandler();
	auto texture = textureHandler.getResourceByName(particleTexture, "particle");
	if (!texture)
	{
		std::cout << "cant create particle, texture not found!" << std::endl;
		return nullptr;
	}
	return std::make_shared<TGC::Particle>(particleTexture);
}

std::shared_ptr<TGC::Item> TGC::Factory::getItem(size_t itemID)
{
	auto itemHandler = TGC::ResoureManager::getInstance().getXMLHandler().getItemHandler();
	auto itemPrefab = itemHandler.getItemPrefabByID(itemID);
	if (itemPrefab.texture.empty() && itemPrefab.name.empty())
	{
		std::cout << "cant create item, prefab object not found!" << std::endl;
		return nullptr;
	}
	auto textureHandler = TGC::ResoureManager::getInstance().getTextureHandler();
	auto texture = textureHandler.getResourceByName(itemPrefab.texture, "item");
	if (!texture)
	{
		std::cout << "cant create item, texture not found!" << std::endl;
		return nullptr;
	}
	return std::make_shared<TGC::Item>(itemPrefab);
}


