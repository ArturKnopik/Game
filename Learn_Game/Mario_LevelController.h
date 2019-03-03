#pragma once
#include <string>
#include "Mario_Level.h"
class LevelController
{
private:
	std::vector<std::pair< std::string, std::shared_ptr<Mario::Level >>> levelList;
	std::shared_ptr<Mario::Level> currentLevel;

public:
	LevelController();
	std::shared_ptr<Mario::Level> getLevel(std::string level);
	void loadLevel(std::string patchToLevel, std::string levelName);
	void switchLevel(std::string level);
	void unloadLevel(std::string level);
	void restartLevel();
	~LevelController();
};

