#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <map>
#include "pugixml.hpp"

namespace TGC
{
	template <typename T>
	class ResourceHandler;

	class TextureLoader
	{
		void parseTextureNode(const pugi::xml_node& itemNode, TGC::ResourceHandler<sf::Texture>& textureHandler);
	public:
		TextureLoader();		
		void loadTexture(ResourceHandler<sf::Texture> & texturehandler);

	};
}

