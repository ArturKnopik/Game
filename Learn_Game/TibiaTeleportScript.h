#pragma once
#include "TibiaScript.h"
namespace TGC
{

	class TeleportScript : public Script
	{	
		size_t teleportDestinyX = 1;
		size_t teleportDestinyY = 1;
		TeleportScript() = delete;
	public:
		TeleportScript(size_t telpoertPositionX, size_t telpoertPositionY);
		void executeScript(Creature *creature);
	};
}
