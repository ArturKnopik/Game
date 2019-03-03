#pragma once
#include <memory>
#include <utility>
#include "Mario_GameObiect.h"
namespace Mario
{

		enum LevelLayer
		{
			BACKGROUND=0,
			MAIN_LAYER=1,
			PARTICLE_LAYER=3
		};
		class Level
		{
			std::vector<std::shared_ptr<Mario::GameObiect>> backgroundObiectList;
			std::vector<std::shared_ptr<Mario::GameObiect>> mainLayerObiectList;
			std::vector<std::shared_ptr<Mario::GameObiect>> particleLayerObiectList;
			std::string name;
		public:
			Level()=delete;
			Level(std::string name);
			void getLevelName();
			void addGameObiect(LevelLayer layer, std::shared_ptr<Mario::GameObiect> gameObiect);
			void removeGameObiect(LevelLayer layer, std::shared_ptr<Mario::GameObiect> gameObiect);
			void removeGameObiect(LevelLayer layer, size_t id);
			std::vector<std::shared_ptr<Mario::GameObiect>> & getObiectList(Mario::LevelLayer layer);
			virtual ~Level() =default;
		};
	
}


