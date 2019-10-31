#pragma once
#include "TibiaEnums.h"
#include "TibiaCreature.h"
namespace TGC
{
	class Script
	{
	protected:
		bool execute = false;
		bool repeatable = false;
		TGC::ENUMS::ScriptTrigerType trigerType = TGC::ENUMS::ScriptTrigerType::ONUSE;
		Script() = delete;
	public:
		Script(TGC::ENUMS::ScriptTrigerType trigerType = TGC::ENUMS::ScriptTrigerType::ONUSE ,bool repeatable = false);
		virtual void executeScript(Creature * creature) = 0;
		bool isSingleExecute();
		const TGC::ENUMS::ScriptTrigerType getTrigerType() const;
		void setTriggerType(TGC::ENUMS::ScriptTrigerType trigerType);
	};
}

