#include "TibiaFactory.h"
#include "TibiaResoureManager.h"
#include "TibiaCreature.h"
#include "TibiaParticle.h"

TGC::Factory::Factory()
{
}

std::shared_ptr<TGC::Creature> TGC::Factory::getMonster(std::string monsterName)
{

	auto monsterHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();
	auto monsterPrefab = monsterHandler.getMonsterPrefabByName(monsterName);
	if (monsterPrefab.texture == "sampleCreature" && monsterPrefab.name == "sample")
	{
		std::cout << "cant create monster, prefab obiect not found!" << std::endl;
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

/*
//TODO: Implemet simple normal obiect creator
std::shared_ptr<TGC::GameObiect> TGC::Factory::getGameObiect(std::string gameObioectName)
{
	return nullptr;
}
*/
