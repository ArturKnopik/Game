#include "TibiaTextureLoader.h"
#include "tinyxml.h"
#include "TibiaResoureManager.h"


void TGC::TextureLoader::loadTexture(TGC::ResourceHandler<sf::Texture> & textureHandler)
{
	TiXmlDocument doc("./resource/XML/Tibia/texture.xml");
	if (!doc.LoadFile())
	{
		std::cout << "error:texture.xml" << std::endl;
		return;
	}

	TiXmlHandle docHandle(&doc);

	TiXmlElement* monsterNode = docHandle.FirstChild("textures").Child("texture", 0).ToElement();

	std::cout << "## Adding texture:" << std::endl;

	while (monsterNode)
	{

		std::string name;
		std::string location;
		std::string usage;

		TiXmlElement* xmlName = monsterNode->FirstChildElement("name");

		if (NULL != xmlName)
		{
			name = xmlName->GetText();
		}

		TiXmlElement* xmlLocation = monsterNode->FirstChildElement("location");

		if (NULL != xmlLocation)
		{
			location = xmlLocation->GetText();
		}

		TiXmlElement* xmlUsage = monsterNode->FirstChildElement("usage");

		if (NULL != xmlUsage)
		{
			usage = xmlUsage->GetText();
		}

		bool addResourceToLost = true;

		if (name.empty())
		{
			addResourceToLost = false;
		}
		if (location.empty())
		{
			addResourceToLost = false;
		}
		if (usage.empty())
		{
			addResourceToLost = false;
		}

		std::shared_ptr<sf::Texture> texture;
		texture = std::make_shared<sf::Texture>();
		if (texture->loadFromFile(location))
		{
			textureHandler.addResource(name, texture, usage);
			std::cout << "  N: " << name << ", L: " << location << ", U: " << usage << std::endl;
		}
		monsterNode = monsterNode->NextSiblingElement("texture");

	}
}

TGC::TextureLoader::TextureLoader()
{

}
