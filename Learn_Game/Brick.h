#pragma once
#include "Mario_GameObiect.h"
#include <iostream>
class Brick
	:public Mario::GameObiect
{
public:
	Brick()=delete;
	Brick(sf::Vector2f position, sf::Vector2f size);
	void update(const float dt);
	virtual ~Brick();
	void onCollision(std::shared_ptr<Mario::GameObiect> other) override;
};

