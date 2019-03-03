#pragma once

#include <memory>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Mario_GameObiect.h"
namespace Mario
{
	class GameObiect;
}
namespace System
{
	enum CollisionType {TOP=0, BOTTOM=1, LEFT=2, RIGHT=3, NO_COLLISION=100};
	//template <class X, class Y>
	//bool checkAABB(std::shared_ptr<X> leftEntity, std::shared_ptr<Y> rightDynamic);

	bool checkAABB(std::shared_ptr<Mario::GameObiect> left, std::shared_ptr<Mario::GameObiect> right);
	CollisionType getCollsionSite(sf::Vector2f positionLeft, sf::Vector2f sizeLeft, sf::Vector2f positionRight, sf::Vector2f sizeRight);
	sf::Vector2f calcCenter(sf::Vector2f position, sf::Vector2f size);

	/*
	template<class X, class Y>
	bool checkAABB(std::shared_ptr<Mario::AnimatedObiect> left, std::shared_ptr<Mario::AnimatedObiect> right)
	{
		return false;
	}
	*/

}