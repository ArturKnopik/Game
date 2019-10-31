#pragma once
#include <string>
#include <unordered_map>
#include "TibiaFactory.h"
namespace TGC
{
	class MonsterPrefab
	{
		int hp = 100;
		std::string texture="default";
		double speed = 3.0;
		std::string name = "default";
	public:
		MonsterPrefab()=default;
		void setHP(int hp);
		void setName(std::string name);
		std::string getName();
		void setSpeed(int speed);
		void setTexture(std::string texture);


		friend class Creature;
		friend class Factory;
	};

	class MonsterLoader
	{
		std::unordered_map<std::string, MonsterPrefab> monstersList;
		
	public:
		MonsterLoader();
		void loadFromFile();
		std::unordered_map<std::string, MonsterPrefab>& getMonsterList();
		MonsterPrefab getMonsterByName(std::string name);

		
	};
}

