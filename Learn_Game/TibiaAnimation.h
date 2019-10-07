#pragma once
#include "TibiaFrame.h"
#include "TibiaEnums.h"
#include "SFML/Graphics/Sprite.hpp"
#include <memory>
namespace TGC
{
	class Animation
	{
		std::shared_ptr<sf::Texture> texture;
		std::vector<TGC::Frame> frameList;
	public:
		Animation();
		void addFrame(TGC::Frame frame);
		void setTexture(std::shared_ptr<sf::Texture> texture);
		const std::shared_ptr<sf::Texture> getTexture() const;
		const sf::IntRect& getFrame(std::size_t index) const;
		const double& getFrameTime(std::size_t index) const;
		std::size_t getSize() const;
	};
}


