#include "TibiaScript.h"


TGC::Script::Script(TGC::ENUMS::ScriptTrigerType trigerType, bool rereatable)
	:trigerType(trigerType), repeatable(rereatable)
{
}

bool TGC::Script::isSingleExecute()
{
	return execute;
}

const TGC::ENUMS::ScriptTrigerType TGC::Script::getTrigerType() const
{
	return trigerType;
}

void TGC::Script::setTriggerType(TGC::ENUMS::ScriptTrigerType trigerType)
{
	this->trigerType = trigerType;
}
