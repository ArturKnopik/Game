#pragma once
#include "Entity.h"
class GravitySystem
{
	float gravityPower;
public:
	GravitySystem();
	~GravitySystem();
	void applyGravity(const float dt, std::vector<std::shared_ptr<Entity>>&  mapEntity);
};

