#include "TibiaFrame.h"


TGC::Frame::Frame(sf::IntRect imagePosition, double timeToNextFrame)
	:imagePosition(imagePosition), timeToNextFrame(timeToNextFrame)
{
}

const double TGC::Frame::getMaxFrameTime() const
{
	return timeToNextFrame;
}

const sf::IntRect TGC::Frame::getFrameRect() const
{
	return imagePosition;
}
