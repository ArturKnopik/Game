#include "TibiaTextureLoader.h"
#include "TibiaResoureManager.h"
#include "TibiaUtilityTools.h"
#include "settings.h"

void TGC::TextureLoader::parseTextureNode(const pugi::xml_node& itemNode, TGC::ResourceHandler<sf::Texture>& textureHandler)
{
	using namespace TGC::UtilityTools;
	std::string name;
	std::string textureAdres;
	std::string usage;
	sf::Vector2i texturePosInResource;
	bool loaWitchOffset = false;

	pugi::xml_attribute locationAttribute = itemNode.attribute("location");
	if (locationAttribute) {
		textureAdres = std::string(itemNode.attribute("location").as_string());
	}


	pugi::xml_attribute nameAttribute = itemNode.attribute("name");
	if (nameAttribute) {
		name = std::string(itemNode.attribute("name").as_string());
	}


	pugi::xml_attribute textureAttribute = itemNode.attribute("usage");
	if (textureAttribute) {
		usage = std::string(textureAttribute.as_string());
	}


	for (auto attributeNode : itemNode.children())
	{
		pugi::xml_attribute keyAttribute = attributeNode.attribute("key");
		if (!keyAttribute) {
			continue;
		}
		std::string tmpStrValue = asLowerCaseString(std::string(keyAttribute.as_string()));

	}
	
		std::shared_ptr<sf::Texture> texture;
		texture = std::make_shared<sf::Texture>();
		if (texture->loadFromFile(textureAdres))
		{
			textureHandler.addResource(name, texture, usage);
			std::cout << "  N: " << name << ", L: " << textureAdres << ", U: " << usage << std::endl;
		}
}

void TGC::TextureLoader::loadTexture(TGC::ResourceHandler<sf::Texture> & textureHandler)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("./resource/XML/Tibia/textures.xml");
	if (!result) {
		std::cout << "error:items.xml" << std::endl;
		return;
	}
	for (auto itemNode : doc.child("textures").children())
	{
		pugi::xml_attribute locationAttribute = itemNode.attribute("location");
		pugi::xml_attribute nameAttribute = itemNode.attribute("name");
		pugi::xml_attribute usageAttribute = itemNode.attribute("usage");
		if (locationAttribute && nameAttribute && usageAttribute)
		{
			parseTextureNode(itemNode, textureHandler);
			continue;
		}
	}
}

TGC::TextureLoader::TextureLoader()
{
}
