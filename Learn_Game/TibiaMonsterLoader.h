#pragma once
#include "pugixml.hpp"
#include <string>
#include <unordered_map>
namespace TGC
{
	class MonsterPrefab
	{
		int hp = 100;
		std::string texture="sampleCreature";
		double speed = 3.0;
		std::string name = "sample";
	public:
		MonsterPrefab()=default;
		void setHP(int hp);
		void setName(std::string name);
		std::string getName();
		void setSpeed(int speed);
		void setTexture(std::string texture);
		friend class Creature;
	};

	class MonsterLoader
	{
		std::unordered_map<std::string, MonsterPrefab> monstersList;
	public:
		MonsterLoader();
		void loadFromFile();
		std::unordered_map<std::string, MonsterPrefab>& getMonsterList();
		MonsterPrefab getMonsterPrefabByName(std::string name);
	};
}

