#include "TibiaAnimation.h"

#include "TibiaTGCGame.h"

TGC::Animation::Animation()
{
}

void TGC::Animation::addFrame(TGC::Frame frame)
{
	frameList.push_back(frame);
}

void TGC::Animation::setTexture(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
}

const std::shared_ptr<sf::Texture> TGC::Animation::getTexture() const
{
	if (texture)
	{
		return texture;
	}
	return nullptr;
}

const sf::IntRect& TGC::Animation::getFrame(std::size_t index) const
{

	if (index < frameList.size() && frameList.size()>0)
	{
		return frameList[index].getFrameRect();
	}
}

const double & TGC::Animation::getFrameTime(std::size_t index) const
{
	if (index < frameList.size() && frameList.size()>0)
	{
		return frameList[index].getMaxFrameTime();
	}
	return 0;
}



std::size_t TGC::Animation::getSize() const
{
	return frameList.size();
}
