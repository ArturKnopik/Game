#pragma once
#include <memory>
#include <utility>
#include "Mario_Gameobject.h"
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
			std::vector<std::shared_ptr<Mario::Gameobject>> backgroundobjectList;
			std::vector<std::shared_ptr<Mario::Gameobject>> mainLayerobjectList;
			std::vector<std::shared_ptr<Mario::Gameobject>> particleLayerobjectList;
			std::string name;
		public:
			Level()=delete;
			Level(std::string name);
			void getLevelName();
			void addGameobject(LevelLayer layer, std::shared_ptr<Mario::Gameobject> gameobject);
			void removeGameobject(LevelLayer layer, std::shared_ptr<Mario::Gameobject> gameobject);
			void removeGameobject(LevelLayer layer, size_t id);
			std::vector<std::shared_ptr<Mario::Gameobject>> & getobjectList(Mario::LevelLayer layer);
			virtual ~Level() =default;
		};
	
}


