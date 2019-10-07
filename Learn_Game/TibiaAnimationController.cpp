#include "TibiaAnimationController.h"

TGC::AnimationController::AnimationController()
	:animationPtr(nullptr), currentFrame(0)
{
}

void TGC::AnimationController::update(const float dt)
{
	if (!isPausedAnimation && animationPtr)
	{
		currentFrameTime += dt;
		if (customFixedFrameTime != 0.0) 
		{
			if (currentFrameTime >= customFixedFrameTime)
			{
				currentFrameTime = 0.0;
				if (currentFrame + 1 < animationPtr->getSize())
				{
					currentFrame++;
				}
				else
				{
					if (!isLoopedAnimation)
					{
						isPausedAnimation = true;
					}
					else
					{
						currentFrame = 0;
					}
				}
				setFrame(currentFrame, false);
			}
		}
		else if (currentFrameTime >= getAnimation()->getFrameTime(currentFrame))
		{
			currentFrameTime = 0.0;
			if (currentFrame + 1 < animationPtr->getSize())
			{
				currentFrame++;
			}
			else
			{
				if (!isLoopedAnimation)
				{
					isPausedAnimation = true;
				}
				else
				{
					currentFrame = 0; 
				}
			}
			setFrame(currentFrame, false);
		}
	}
}

void TGC::AnimationController::setAnimation(TGC::Animation& animation)
{
	animationPtr = &animation;
	texture = animation.getTexture();
	currentFrame = 0;
	setFrame(currentFrame);
}

void TGC::AnimationController::play()
{
	isPausedAnimation = false;
}

void TGC::AnimationController::pause()
{
	isPausedAnimation = true;
}

void TGC::AnimationController::stop()
{
	isPausedAnimation = true;
	currentFrame = 0;
	setFrame(currentFrame);
}

void TGC::AnimationController::setLooped(bool looped)
{
	isLoopedAnimation = looped;
}

const TGC::Animation* TGC::AnimationController::getAnimation() const
{
	return animationPtr;
}

bool TGC::AnimationController::isLooped() const
{
	return this->isLoopedAnimation;
}

bool TGC::AnimationController::isPlaying() const
{
	return isPausedAnimation;
}

double TGC::AnimationController::getFrameTime(std::size_t index) const
{
	if(customFixedFrameTime!=0)
	{
		return animationPtr->getFrameTime(index);
	}
	return customFixedFrameTime;
}

void TGC::AnimationController::setFrame(std::size_t newFrame, bool resetTime)
{
	if (animationPtr)
	{
		sf::IntRect rect = animationPtr->getFrame(newFrame);
	}

	if (resetTime)
	{
		currentFrameTime = 0;
	}
	
}

const std::shared_ptr<sf::Texture> TGC::AnimationController::getTexture() const
{
	return texture;
}

const size_t TGC::AnimationController::getCurrentFrame() const
{
	return currentFrame;
}
