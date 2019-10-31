#include "Mario_Level.h"


void Mario::Level::addGameobject(LevelLayer layer, std::shared_ptr<Mario::Gameobject> gameobject)
{
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		backgroundobjectList.push_back(gameobject);

		break;
	case LevelLayer::MAIN_LAYER:
		mainLayerobjectList.push_back(gameobject);

		break;
	case LevelLayer::PARTICLE_LAYER:
		particleLayerobjectList.push_back(gameobject);
		break;
	default:
		printf("CANNOT ADD object TO LIST");
		break;
	}
}

void Mario::Level::removeGameobject(LevelLayer layer,  std::shared_ptr<Mario::Gameobject> gameobject)
{
	std::vector<std::shared_ptr<Mario::Gameobject>>::iterator it = backgroundobjectList.begin();
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		for (it; it != backgroundobjectList.end(); it++)
		{
			if ((*it).get() == gameobject.get())
			{
				backgroundobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::MAIN_LAYER:
		for (it; it != mainLayerobjectList.end(); it++)
		{
			if ((*it).get() == gameobject.get())
			{
				mainLayerobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::PARTICLE_LAYER:
		for (it; it != particleLayerobjectList.end(); it++)
		{
			if ((*it).get() == gameobject.get())
			{
				particleLayerobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	}
}

void Mario::Level::removeGameobject(LevelLayer layer, size_t id)
{
	std::vector<std::shared_ptr<Mario::Gameobject>>::iterator it = backgroundobjectList.begin();
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		for (it; it != backgroundobjectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				backgroundobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::MAIN_LAYER:
		for (it; it != mainLayerobjectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				mainLayerobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::PARTICLE_LAYER:
		for (it; it != particleLayerobjectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				particleLayerobjectList.erase(it);
				return;
			}
			printf("Gameobject dont't exist, cant erase element");;
		}
		break;
	}
}

std::vector<std::shared_ptr<Mario::Gameobject>> & Mario::Level::getobjectList(Mario::LevelLayer layer)
{
	switch (layer)
	{
	case Mario::LevelLayer::BACKGROUND:
		return backgroundobjectList;
		break;
	case Mario::LevelLayer::MAIN_LAYER:
		return mainLayerobjectList;
		break;
	case Mario::LevelLayer::PARTICLE_LAYER:
		return particleLayerobjectList;
		
		break;
	}
}




