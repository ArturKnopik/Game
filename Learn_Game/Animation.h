#pragma once
#include <vector>
#include "AnimationFrame.h"
namespace Animation
{
	enum AnimationType
	{
		MULTIPLE_FRAME=0,
		ROTATE_MULTIPLE_FRAME=1
	};

	class Animation
	{
		float animationCurrntTime;
		int currentFrame;
		std::vector<std::vector<AnimationFrame>> frames;
		AnimationType type;
		void updateMultipleFrame(const float dt);
		void updateRotateMultipleFrame(const float dt);

	public:
		Animation(AnimationType obietType);
		~Animation();
		void update(const float dt);
		void setIdelStatus(int frame);
	};

}

