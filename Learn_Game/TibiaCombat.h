#pragma once
#include "TibiaEnums.h"
#include <memory>
#include "TibiaCreature.h"
#include "UtilityTools.h"
namespace TGC
{
	class Combat
	{
		TGC::ENUMS::CombatType type;
		int value;
	public:
		Combat() = delete;
		Combat(TGC::ENUMS::CombatType type, int value);
		int getValue();
		TGC::ENUMS::CombatType getType();
		void changeValue(int value);
		void addToDamage(int value);
	};

	class Combatobject
	{
		TGC::Creature * attacker;
		std::shared_ptr<TGC::Creature> target;
		Combat combat;
	public:
		Combatobject() = delete;
		Combatobject(TGC::Creature * attacker, std::shared_ptr<TGC::Creature> target, Combat combat);
		TGC::Creature * getAttacker();
		std::shared_ptr<TGC::Creature> getTarget();
		Combat getCombat();
	};
}

