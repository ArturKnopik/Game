#include "Combat.h"

TGC::Combat::Combat::Combat(TGC::ENUMS::CombatType type, int value)
	:type(type), value(value)
{

}

int TGC::Combat::getValue()
{
	return value;
}

TGC::ENUMS::CombatType TGC::Combat::getType()
{
	return type;
}

void TGC::Combat::changeValue(int value)
{
	if (value < 0)
	{
		value = 0;
		return;
	}
	this->value = value;
}
