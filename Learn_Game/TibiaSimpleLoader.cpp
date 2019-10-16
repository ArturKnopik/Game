#include "TibiaSimpleLoader.h"

TGC::TibiaSimpleLoader::TibiaSimpleLoader()
{
	//TODO: loading resource list from file then try load this resource
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/Tibia/sample.png");
	TGC::ResoureManager::getInstance().getTextureHandler().addResource("sample", texture);

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/Tibia/playerJMP.png");
	TGC::ResoureManager::getInstance().getTextureHandler().addResource("player", texture);

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/EnemyGraphic.png");
	ResoureManager::getInstance().getTextureHandler().addResource("rat", texture);

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/Tibia/testParticle.png");
	TGC::ResoureManager::getInstance().getTextureHandler().addResource("sampleParticle", texture);


}
