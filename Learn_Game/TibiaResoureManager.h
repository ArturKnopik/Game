#pragma once
#include <unordered_map>
#include <memory>
#include "TibiaResourceHandler.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"
#include "TibiaXMLLoader.h"
#include "TibiaTextureLoader.h"
namespace TGC
{
	class ResoureManager
	{
		TGC::TextureLoader textureLoader;
		TGC::ResourceHandler<sf::Texture> textureHandler;
		TGC::ResourceHandler<sf::Sound> soundHandler;
		TGC::XMLLoader xmlLoader;
		ResoureManager();
		ResoureManager(ResoureManager&&) = delete;
		ResoureManager(ResoureManager&) = delete;
	public:
		~ResoureManager() = default;
		static ResoureManager& getInstance();
		TGC::ResourceHandler<sf::Texture>& getTextureHandler();
		TGC::ResourceHandler<sf::Sound>& getSoundHandler();
		TGC::XMLLoader & getXMLHandler();
	};
}

