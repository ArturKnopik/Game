#pragma once
namespace TGC
{
	class GlobalAnimationTimer final // don't allow inheritance from this class in future, class used to globaly menagment animation without own timer e.g. static tile like water and water with a wave
	{
		double maxGlobalAnimationTime = 0.3;
		double currentGlobalAnimationTime = 0.0;
	public:
		void updateAnimationTime(const double dt);
		bool isEndAnimationTimeReached();
	};
}
