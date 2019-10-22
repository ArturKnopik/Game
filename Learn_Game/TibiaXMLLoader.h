#pragma once
#include "TibiaMonsterLoader.h"
#include "TibiaItemLoader.h"

namespace TGC
{
	class XMLLoader
	{
		MonsterLoader monstersPrefabList;
		ItemLoader itemPrefabList;
	public:
		XMLLoader()=default;
		const MonsterLoader& getMonstersHandler();
		const ItemLoader& getItemHandler();
	};
}

