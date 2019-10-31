#pragma once
#include "TibiaMonsterLoader.h"
#include "TibiaItemLoader.h"
#include "TibiaWorldLoader.h"
namespace TGC
{
	class XMLLoader
	{
		MonsterLoader monstersPrefabList;
		ItemLoader itemPrefabList;
		WorldLoader worldLoader;
	public:
		XMLLoader();
		const MonsterLoader& getMonstersHandler();
		const ItemLoader& getItemHandler();
		const WorldLoader& getWorldLoader();
	};
}

