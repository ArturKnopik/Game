#pragma once
#include "TibiaEnums.h"
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
		void decreseDamage(int value);
	};

}

