#include "TibiaXMLLoader.h"

const TGC::MonsterLoader& TGC::XMLLoader::getMonstersHandler()
{
	return monstersPrefabList;
}

const TGC::ItemLoader& TGC::XMLLoader::getItemHandler()
{
	return itemPrefabList;
}
