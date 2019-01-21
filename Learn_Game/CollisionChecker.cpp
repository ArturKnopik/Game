#include "CollisionChecker.h"

#include <iostream>
#include <math.h>

namespace CollsionChecker
{
	template <class X, class Y>
	bool checkAABB(std::shared_ptr<X> leftEntity, std::shared_ptr<Y> rightDynamic)
	{
		if (leftEntity->getPosition().x < rightDynamic->getPosition().x + rightDynamic->getSize().x &&
			leftEntity->getPosition().x + leftEntity->getSize().x > rightDynamic->getPosition().x &&
			leftEntity->getPosition().y < rightDynamic->getPosition().y + rightDynamic->getSize().y &&
			leftEntity->getSize().y + leftEntity->getPosition().y > rightDynamic->getPosition().y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

bool System::checkAABB(sf::Vector2f positionLeft, sf::Vector2f sizeLeft, sf::Vector2f positionRight, sf::Vector2f sizeRight)
{
	if (positionLeft.x < positionRight.x + sizeRight.x &&
		positionLeft.x + sizeLeft.x > positionRight.x &&
		positionLeft.y < positionRight.y + sizeRight.y &&
		sizeLeft.y + positionLeft.y > positionRight.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
