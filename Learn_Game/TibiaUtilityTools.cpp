#include "TibiaUtilityTools.h"

size_t TGC::UtilityTools::UniqueIDGenerator::next()
{
	 return id++; 
}

TGC::UtilityTools::UniqueIDGenerator::UniqueIDGenerator()
	: id(0)
{
}

short TGC::UtilityTools::damageTypeToIndex(TGC::ENUMS::CombatType type)
{
	switch (type)
	{
	case TGC::ENUMS::PHYSICAL:
		return 0;
		break;
	case TGC::ENUMS::FIRE:
		return 1;
		break;
	case TGC::ENUMS::EARTH:
		return 2;
		break;
	case TGC::ENUMS::ICE:
		return 3;
		break;
	case TGC::ENUMS::ENERGY:
		return 4;
		break;
	case TGC::ENUMS::HEALING:
		return 5;
		break;
	default:
		return 0;
		break;
	}
}
