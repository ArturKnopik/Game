#pragma once
#include <string>
#include <unordered_map>
#include "TibiaFactory.h"
namespace TGC
{
	class MonsterPrefab
	{
		int hp = 100;
		std::string texture="";
		double speed = 3.0;
		std::string name = "";
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
		void loadFromFile();
	public:
		MonsterLoader();
		
		std::unordered_map<std::string, MonsterPrefab>& getMonsterList();
		MonsterPrefab getMonsterByName(std::string name);

		
	};
}

