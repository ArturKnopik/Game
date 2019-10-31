#pragma once
#include "TibiaScript.h"
namespace TGC
{

	class SpawnScript : public Script
	{	
		size_t spawnMonsterPosX = 1;
		size_t spawnMonsterPosY = 1;
		std::string monsterName;
		SpawnScript() = delete;
	public:
		SpawnScript(size_t spawnMonsterPosX, size_t spawnMonsterPosY, std::string monsterName);
		void executeScript(Creature *creature);
	};
}
