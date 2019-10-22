#include "TibiaMonsterLoader.h"
#include <iostream>
#include "tinyxml.h"
TGC::MonsterLoader::MonsterLoader()
{
	loadFromFile();
}
void TGC::MonsterLoader::loadFromFile()
{
	TiXmlDocument doc("./resource/XML/Tibia/monsters.xml");
	if (!doc.LoadFile())
	{
		std::cout << "error:monsters.xml"<< std::endl;
		return;
	}
	
	TiXmlHandle docHandle(&doc);

	TiXmlElement* monsterNode = docHandle.FirstChild("monsters").Child("monster", 0).ToElement();

	while (monsterNode)
	{
		MonsterPrefab monster;
		std::string name;
		std::string texture;
		int hp;
		int speed;
		TiXmlElement* monsterName = monsterNode->FirstChildElement("name");

		if (NULL != monsterName)
		{
			name = monsterName->GetText();
			monster.setName(name);
		}

		TiXmlElement* monsterTexture = monsterNode->FirstChildElement("texture");

		if (NULL != monsterTexture)
		{
			texture = monsterTexture->GetText();
			monster.setTexture(texture);
		}

		TiXmlElement* monsterHp = monsterNode->FirstChildElement("hitpoints");

		if (NULL != monsterHp)
		{
		//	monsterTexture.inte
		
			hp = std::stoi(monsterHp->GetText());
			monster.setHP(hp);
		}

		TiXmlElement* monsterSpeed = monsterNode->FirstChildElement("speed");

		if (NULL != monsterSpeed)
		{
			//	monsterTexture.inte
			speed = std::stoi(monsterSpeed->GetText());
			monster.setSpeed(speed);
		}
		monstersList.insert({ name, monster });

		monsterNode = monsterNode->NextSiblingElement("monster");

	}
}

std::unordered_map<std::string, TGC::MonsterPrefab>& TGC::MonsterLoader::getMonsterList()
{
	return monstersList;
}

TGC::MonsterPrefab TGC::MonsterLoader::getMonsterByName(std::string name)
{	
	for (auto it = monstersList.begin(); it != monstersList.end(); it++)
	{
		if (it->first == name)
		{
			return it->second;
		}
	}
	MonsterPrefab monsterPrefab;
	return  monsterPrefab;
}

void TGC::MonsterPrefab::setHP(int hp)
{
	this->hp = hp;
}

void TGC::MonsterPrefab::setName(std::string name)
{
	this->name = name;
}

std::string TGC::MonsterPrefab::getName()
{
	return name;
}

void TGC::MonsterPrefab::setSpeed(int speed)
{
	this->speed = speed;
}

void TGC::MonsterPrefab::setTexture(std::string texture)
{
	this->texture = texture;
}
