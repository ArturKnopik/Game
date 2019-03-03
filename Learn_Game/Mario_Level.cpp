#include "Mario_Level.h"


void Mario::Level::addGameObiect(LevelLayer layer, std::shared_ptr<Mario::GameObiect> gameObiect)
{
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		backgroundObiectList.push_back(gameObiect);

		break;
	case LevelLayer::MAIN_LAYER:
		mainLayerObiectList.push_back(gameObiect);

		break;
	case LevelLayer::PARTICLE_LAYER:
		particleLayerObiectList.push_back(gameObiect);
		break;
	default:
		printf("CANNOT ADD OBIECT TO LIST");
		break;
	}
}

void Mario::Level::removeGameObiect(LevelLayer layer,  std::shared_ptr<Mario::GameObiect> gameObiect)
{
	std::vector<std::shared_ptr<Mario::GameObiect>>::iterator it = backgroundObiectList.begin();
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		for (it; it != backgroundObiectList.end(); it++)
		{
			if ((*it).get() == gameObiect.get())
			{
				backgroundObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::MAIN_LAYER:
		for (it; it != mainLayerObiectList.end(); it++)
		{
			if ((*it).get() == gameObiect.get())
			{
				mainLayerObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::PARTICLE_LAYER:
		for (it; it != particleLayerObiectList.end(); it++)
		{
			if ((*it).get() == gameObiect.get())
			{
				particleLayerObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	}
}

void Mario::Level::removeGameObiect(LevelLayer layer, size_t id)
{
	std::vector<std::shared_ptr<Mario::GameObiect>>::iterator it = backgroundObiectList.begin();
	switch (layer)
	{
	case LevelLayer::BACKGROUND:
		for (it; it != backgroundObiectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				backgroundObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::MAIN_LAYER:
		for (it; it != mainLayerObiectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				mainLayerObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	case LevelLayer::PARTICLE_LAYER:
		for (it; it != particleLayerObiectList.end(); it++)
		{
			if ((*it)->getID() == id)
			{
				particleLayerObiectList.erase(it);
				return;
			}
			printf("GameObiect dont't exist, cant erase element");;
		}
		break;
	}
}

std::vector<std::shared_ptr<Mario::GameObiect>> & Mario::Level::getObiectList(Mario::LevelLayer layer)
{
	switch (layer)
	{
	case Mario::LevelLayer::BACKGROUND:
		return backgroundObiectList;
		break;
	case Mario::LevelLayer::MAIN_LAYER:
		return mainLayerObiectList;
		break;
	case Mario::LevelLayer::PARTICLE_LAYER:
		return particleLayerObiectList;
		
		break;
	}
}




