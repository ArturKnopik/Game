#pragma once
#include "TibiaAnimation.h"
namespace TCG
{
	class AnimationController
	{

		const Animation* animationPtr;
		double customFixedFrameTime = 0; // change this value if want use fixed time frame time value
		double currentFrameTime = 0;
		std::size_t currentFrame = 0;
		bool isPausedAnimation = true;
		bool isLoopedAnimation = true;
		std::shared_ptr<sf::Texture> texture;

	public:
		AnimationController();
		AnimationController(const AnimationController&) = default;
		void update(const float dt);
		void setAnimation(Animation& animation);
		void play();
		void pause();
		void stop();
		void setLooped(bool looped);
		const Animation* getAnimation() const;
		bool isLooped() const;
		bool isPlaying() const;
		double getFrameTime(std::size_t index = 0) const;
		void setFrame(std::size_t newFrame, bool resetTime = true);
		const std::shared_ptr<sf::Texture> getTexture() const;
		const size_t getCurrentFrame() const;
	};
}

