#include "ResourceManager.h"
#include <iostream>

System::ResourceManager::ResourceManager()
{
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/Mario/Template.png");
	addResource(texture, "default");
}



System::ResourceManager & System::ResourceManager::getInstance()
{
	static ResourceManager s;
	return s;	
}

const std::vector<std::pair<std::shared_ptr<sf::Texture>, std::string>>& System::ResourceManager::getTextureList() const
{
	return textureList;
}

void System::ResourceManager::addResource(std::shared_ptr<sf::Texture> texture, std::string name)
{
	std::pair<std::shared_ptr<sf::Texture>, std::string> tempPair(texture, name);
	for (auto it = textureList.begin(); it != textureList.end(); it++)
	{
		if(it->second==name)
		{
			std::cout << "error, texture named '"<<name<<"' exist in list" << std::endl;
			return;
		}
	}
	textureList.push_back(std::move(std::pair<std::shared_ptr<sf::Texture>, std::string>(texture, name)));
	std::cout << "Added '" << name << "' to list" << std::endl;
	
}

std::shared_ptr<sf::Texture> System::ResourceManager::getTexture(std::string name)
{
	for (auto it = textureList.begin(); it != textureList.end(); it++)
	{
		if(it->second==name)
		{
			return it->first;
		}	
	}
	std::cout << "returned nullptr" << std::endl;
	return nullptr;
}


