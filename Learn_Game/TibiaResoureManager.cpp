#include "TibiaResoureManager.h"

TGC::ResoureManager& TGC::ResoureManager::getInstance()
{
	static ResoureManager rscmgr;
	return rscmgr;
}

TGC::ResourceHandler<sf::Texture>& TGC::ResoureManager::getTextureHandler()
{
	return textureHandler;
}

TGC::ResourceHandler<sf::Sound>& TGC::ResoureManager::getSoundHandler()
{
	return soundHandler;
}
