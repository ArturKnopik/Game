#pragma once
#include "TibiaMonsterLoader.h"

namespace TGC
{
	class XMLLoader
	{
		MonsterLoader monstersPrefabList;
	public:
		XMLLoader()=default;
		const MonsterLoader& getMonstersHandler();
	};
}

