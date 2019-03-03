#include "Mario_LevelController.h"
#include <tinyxml.h>
#include <fstream>
#include "Brick.h"
std::shared_ptr<Mario::Level> LevelController::getLevel(std::string level)
{
	/*
	std::vector<std::pair< std::string, std::shared_ptr<Mario::Level >>>::iterator it = levelList.begin();
	for (it = levelList.begin(); it != levelList.end(); it++)
	{
		if ((*it).first == level)
		{
			printf("LEVEL ALREADY IN MEMORY");
			return (*it).second;
		}
	}

	std::shared_ptr<Mario::Level > currentLoadLevel = std::make_shared< Mario::Level>(level);


	//currentLevel = currentLoadLevel;
	levelList.push_back(std::make_pair(level, currentLoadLevel));
	return currentLoadLevel;
	*/
	std::shared_ptr<Mario::Level > currentLoadLevel = std::make_shared< Mario::Level>(level);
	std::ifstream file;
	file.open("level.txt");
	if (!file.is_open())
	{
		std::cout << "can't load level" << std::endl;
	}

	int w, h;
	file >> w;
	file >> h;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			char x;
			file >> x;
			if (x == 'B')
			{
				currentLoadLevel->addGameObiect(Mario::LevelLayer::MAIN_LAYER, std::make_shared<Brick>(sf::Vector2f(j * 32, i * 32), sf::Vector2f(32, 32)));
			}
		}
	}

	file.close();
	return currentLoadLevel;
}

LevelController::LevelController()
{
}

void LevelController::loadLevel(std::string patchToLevel, std::string levelName)
{
	//TODO use XML to load lvl
	/*
	std::shared_ptr<Mario::Level > currentLoadLevel = std::make_shared< Mario::Level>(levelName);
	std::ifstream file;
	file.open("level.txt");
	if (!file.is_open())
	{
		std::cout << "can't load level" << std::endl;
	}

	int w, h;
	file >> w;
	file >> h;
	for (int i = 0; i < w ; i++)
	{
		for (int j = 0; j < h; j++)
		{
			char x;
			file >> x;
			if (x == 'B')
			{
				currentLoadLevel->addGameObiect(Mario::LevelLayer::MAIN_LAYER ,std::make_shared<Brick>(Brick(sf::Vector2f(i * 32, j * 32), sf::Vector2f(32, 32))));
			}
		}
	}

	file.close();


	std::vector<std::pair< std::string, std::shared_ptr<Mario::Level >>>::iterator it = levelList.begin();
	for (it = levelList.begin(); it != levelList.end(); it++)
	{
		if ((*it).first == patchToLevel)
		{
			printf("LEVEL ALREADY IN MEMORY");
			return;
		}		
	}
	
	currentLevel = currentLoadLevel;
	std::cout << "currentLevel: " << currentLevel->getObiectList(Mario::LevelLayer::MAIN_LAYER).size() << std::endl;
	*/
}


void LevelController::switchLevel(std::string level)
{
	std::vector<std::pair< std::string, std::shared_ptr<Mario::Level >>>::iterator it = levelList.begin();
	for (it = levelList.begin(); it != levelList.end(); it++)
	{
		if ((*it).first == level)
		{
			currentLevel = (*it).second;
			printf("LEVEL IN MEMORY/n");
			return;
		}
	}
	printf("LOAD LEVEL FROM HARDDRIVE/n");

	std::shared_ptr<Mario::Level> newLevel = getLevel(level);
	currentLevel = newLevel;
}

void LevelController::unloadLevel(std::string level)
{
	std::vector<std::pair< std::string, std::shared_ptr<Mario::Level >>>::iterator it = levelList.begin();
	for (it = levelList.begin(); it != levelList.end(); it++)
	{
		if ((*it).first == level)
		{
			levelList.erase(it);
			printf("LEVEL REMOVED/n");
			return;
		}
	}
}

void LevelController::restartLevel()
{
	//TODO: reload lvl from file
}

LevelController::~LevelController()
{
}
