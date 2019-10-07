#include "TibiaGlobalAnimationTimer.h"

void TGC::GlobalAnimationTimer::updateAnimationTime(const float dt)
{
	if (currentGlobalAnimationTime < maxGlobalAnimationTime)
	{
		currentGlobalAnimationTime += dt;
	}
}

bool TGC::GlobalAnimationTimer::isEndAnimationTimeReached()
{
	if (currentGlobalAnimationTime > maxGlobalAnimationTime)
	{
		return true;
	}
	return false;
}
