#include "TibiaUtilityTools.h"

size_t TGC::UtilityTools::UniqueIDGenerator::next()
{
	 return id++; 
}

TGC::UtilityTools::UniqueIDGenerator::UniqueIDGenerator()
	: id(0)
{
}
