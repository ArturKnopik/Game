#include "TeleportScript.h"
#include "TibiaTGCGame.h"
TGC::SpawnScript::SpawnScript(size_t teleportDestinyX, size_t teleportDestinyY)
	:Script(TGC::ENUMS::ScriptTrigerType::ONUSE, true), teleportDestinyX(teleportDestinyX), teleportDestinyY(teleportDestinyY)
{
}

void TGC::SpawnScript::executeScript(Creature * creature)
{
	auto creatureCell = TGC::Global::TGCGame::getSingleton().getXYCoordinateCell(creature->getPosition().x, creature->getPosition().y);
	auto cellCreature = creatureCell->getCreature();
	auto targetTeleportCell = TGC::Global::TGCGame::getSingleton().getXYCoordinateCell(teleportDestinyX, teleportDestinyY);
	targetTeleportCell->addCreature(creature);
	creatureCell->removeCreature();
	creature->restartWalkingTime(true);
	std::cout << "execute" << std::endl;

}
