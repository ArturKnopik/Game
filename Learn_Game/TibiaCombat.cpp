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

void TGC::Combat::addToDamage(int value)
{
	this->value += value;
	if (this->value < 0) // posible to add negativ numbers;
	{
		this->value = 0;
		return;
	}
}



TGC::CombatObiect::CombatObiect(TGC::Creature * attacker, std::shared_ptr<TGC::Creature> target, TGC::Combat combat)
	:attacker(attacker), target(target), combat(combat)
{
}

TGC::Creature * TGC::CombatObiect::getAttacker()
{
	return attacker;
}

std::shared_ptr<TGC::Creature> TGC::CombatObiect::getTarget()
{
	return target;
}

TGC::Combat TGC::CombatObiect::getCombat()
{
	return combat;
}
