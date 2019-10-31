#include "TibiaTeleportScript.h"
#include "TibiaTGCGame.h"

TGC::TeleportScript::TeleportScript(size_t telpoertPositionX, size_t telpoertPositionY)
	:Script(TGC::ENUMS::ScriptTrigerType::ONUSE, true), teleportDestinyX(telpoertPositionX), teleportDestinyY(telpoertPositionY)
{

}

void TGC::TeleportScript::executeScript(Creature* creature)
{
	//auto creature = TGC::Global::TGCGame::getSingleton().getPlayer();
	auto playerCell = TGC::Global::TGCGame::getSingleton().getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y);
	auto player = TGC::Global::TGCGame::getSingleton().getPlayer();

	auto destinyCell = TGC::Global::TGCGame::getSingleton().getXYCoordinateCell(teleportDestinyX, teleportDestinyY);
	if (destinyCell->getGround() && !destinyCell->getCreature())
	{
		if (playerCell->getCreature())
		{
			playerCell->removeCreature();
		}
		creature->setPosition({ teleportDestinyX, teleportDestinyY });
		destinyCell->addCreature(player);
	}
	creature->restartWalkingTime(true);
	std::unique_ptr<Particle> partToAdd = std::make_unique<Particle>(teleportDestinyX, teleportDestinyY, "teleportParticle");
	TGC::Global::TGCGame::getSingleton().addParticle(std::move(partToAdd));
}
