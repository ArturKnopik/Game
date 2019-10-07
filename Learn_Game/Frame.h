#pragma once
#include "SFML/Graphics/Rect.hpp"
#include <vector>
namespace TCG
{
	class Frame
	{
		double timeToNextFrame = 0.5;
		sf::IntRect imagePosition;
	public:
		Frame() = delete;
		Frame(sf::IntRect imagePosition, double timeToNextFrame = 0.1);
		const double getMaxFrameTime() const;
		const sf::IntRect getFrameRect() const;
	};
}

