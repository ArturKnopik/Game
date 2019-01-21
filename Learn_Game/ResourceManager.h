#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <utility>
#include <string>
namespace System
{
	enum ResourceType{ TEXTURE, SOUND };

	class ResourceManager
	{
	private:
		int i = 5;
		std::vector<std::pair<std::shared_ptr<sf::Texture>, std::string>> textureList;
		static ResourceManager s;
		// default c-tor
		ResourceManager();
		// delete
		ResourceManager(const ResourceManager&) = delete;
		// delete
		ResourceManager(ResourceManager&&) =delete;
		// delete
		ResourceManager& operator=(const ResourceManager&)=delete;
		// delete
		ResourceManager& operator=(ResourceManager&&) =delete;

	public:
		// return Instance of this obiect (singleton)
		static ResourceManager & getInstance();
		// d
		~ResourceManager()=default;
		const std::vector<std::pair<std::shared_ptr<sf::Texture>, std::string>>  & getTextureList() const;
		void addResource(std::shared_ptr<sf::Texture> texture, std::string name);
		std::shared_ptr<sf::Texture> getTexture(std::string name);
	};

}

