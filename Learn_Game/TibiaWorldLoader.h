#pragma once
#include <pugixml.hpp>
#include "TibiaWorld.h"

namespace TGC
{
	class WorldLoader
	{
		std::shared_ptr<World> loadedWorldPRT;
		void parseWorldNode(const pugi::xml_node& itemNode);
	public:
		WorldLoader();
		void loadFromFile();
		std::shared_ptr<TGC::World> & getWorld();
	};
}

