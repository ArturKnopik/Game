#pragma once
#include <memory>
#include "TibiaResoureManager.h"
namespace TGC
{
	class TibiaSimpleLoader
	{
		std::shared_ptr<sf::Texture> texture;
	public:
		TibiaSimpleLoader();
	};
}

