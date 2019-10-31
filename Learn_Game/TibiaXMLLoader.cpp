#include "TibiaXMLLoader.h"

TGC::XMLLoader::XMLLoader()
{
	itemPrefabList.loadFromFile();
	monstersPrefabList.loadFromFile();
}

const TGC::MonsterLoader& TGC::XMLLoader::getMonstersHandler()
{
	return monstersPrefabList;
}

const TGC::ItemLoader& TGC::XMLLoader::getItemHandler()
{
	return itemPrefabList;
}

const TGC::WorldLoader& TGC::XMLLoader::getWorldLoader()
{
	return worldLoader;
}
