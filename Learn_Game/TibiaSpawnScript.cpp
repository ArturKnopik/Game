#include "TibiaSpawnScript.h"
#include "TibiaTGCGame.h"
#include "TibiaResoureManager.h"

TGC::SpawnScript::SpawnScript(size_t spawnMonsterPosX, size_t spawnMonsterPosY, std::string monsterName)
	:Script(TGC::ENUMS::ScriptTrigerType::ONUSE, true), spawnMonsterPosX(spawnMonsterPosX), spawnMonsterPosY(spawnMonsterPosY), monsterName(monsterName)
{

}

void TGC::SpawnScript::executeScript(Creature* creature)
{
	auto& tgcGlobal = TGC::Global::TGCGame::getSingleton();
	auto targetCell = tgcGlobal.getXYCoordinateCell(spawnMonsterPosX, spawnMonsterPosY);
	auto monsterHandler = TGC::ResoureManager::getInstance().getXMLHandler().getMonstersHandler();
	auto monster = std::make_shared<Creature>(monsterHandler.getMonsterByName(monsterName));
	if (!monster)
	{
		return;
	}
	monster->setPosition(sf::Vector2<size_t>(spawnMonsterPosX, spawnMonsterPosY));
	targetCell->addCreature(monster);
	std::unique_ptr<Particle> partToAdd = std::make_unique<Particle>(spawnMonsterPosX, spawnMonsterPosY, "teleportParticle");
	TGC::Global::TGCGame::getSingleton().addParticle(std::move(partToAdd));
}
