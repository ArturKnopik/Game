#pragma once
#include "TibiaScript.h"
namespace TGC
{

	class SpawnScript : public Script
	{	
		size_t teleportDestinyX = 1;
		size_t teleportDestinyY = 1;
		SpawnScript() = delete;
	public:
		SpawnScript(size_t teleportDestinyX, size_t teleportDestinyY);
		void executeScript(Creature *creature);
	};
}
