#include "GravitySystem.h"



GravitySystem::GravitySystem()
	:gravityPower(0.0001f)
{
}


GravitySystem::~GravitySystem()
{
}

void GravitySystem::applyGravity(const float dt, std::vector<std::shared_ptr<Entity>>&  mapEntityy)
{
	for (std::vector<std::shared_ptr<Entity>>::iterator iter= mapEntityy.begin(); iter != mapEntityy.end(); iter++)
	{
		/*
		if ((*iter)->canGravityModifyThis())
		{
			if (!(*iter)->isCollisionAble())
			{
				if ((*iter)->canGravityModifyThis())
				{
					(*iter)->setNewPosition(sf::Vector2f((*iter)->getPosition().x, (*iter)->getPosition().y + (gravityPower*dt)));
				}			
			}
		}	
		*/
	}
}
