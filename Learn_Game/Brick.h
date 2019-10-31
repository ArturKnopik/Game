#pragma once
#include "Mario_Gameobject.h"
#include <iostream>
class Brick
	:public Mario::Gameobject
{
public:
	Brick()=delete;
	Brick(sf::Vector2f position, sf::Vector2f size);
	void update(const double dt);
	virtual ~Brick();
	void onCollision(std::shared_ptr<Mario::Gameobject> other) override;
};

