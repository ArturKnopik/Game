#include "TibiaCombat.h"

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

void TGC::Combat::decreseDamage(int value)
{
	this->value -= value;
	if (this->value < 0)
	{
		this->value = 0;
		return;
	}
}
