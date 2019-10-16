#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <map>


namespace TGC
{
	template <typename T>
	class ResourceHandler;

	class TextureLoader
	{
	public:
		TextureLoader();
		void loadTexture(ResourceHandler<sf::Texture> & texturehandler);

	};
}

