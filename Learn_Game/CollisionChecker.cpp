#include "CollisionChecker.h"

#include <iostream>
#include <math.h>
namespace System
{
	bool System::checkAABB(std::shared_ptr<Mario::Gameobject> left, std::shared_ptr<Mario::Gameobject> right)
	{

		if (left->getPosition().x <= right->getPosition().x + right->getSize().x &&
			left->getPosition().x + left->getSize().x >= right->getPosition().x &&
			left->getPosition().y <= right->getPosition().y + right->getSize().y &&
			left->getSize().y + left->getPosition().y >= right->getPosition().y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	System::CollisionType System::getCollsionSite(sf::Vector2f positionLeft, sf::Vector2f sizeLeft, sf::Vector2f positionRight, sf::Vector2f sizeRight)
	{

		double dx = (positionLeft.x + (sizeLeft.x / 2)) - (positionRight.x + (sizeRight.x / 2));
		double dy = (positionLeft.y + (sizeLeft.y / 2)) - (positionRight.y + (sizeRight.y / 2));
		double width = (sizeLeft.x + sizeLeft.x) / 2;
		double height = (sizeLeft.y + sizeLeft.y) / 2;
		double crossWidth = width * dy;
		double crossHeight = height * dx;
		System::CollisionType collision = System::CollisionType::NO_COLLISION;
		if (abs(dx) <= width && abs(dy) <= height) {

			if (crossWidth > crossHeight) {
				collision = (crossWidth > (-crossHeight)) ? System::CollisionType::BOTTOM : System::CollisionType::LEFT;
			}
			else {
				collision = (crossWidth > -(crossHeight)) ? System::CollisionType::RIGHT : System::CollisionType::TOP;
			}
		}
		return(collision);
	}

	sf::Vector2f System::calcCenter(sf::Vector2f position, sf::Vector2f size)
	{
		return sf::Vector2f(position.x + (size.x / 2), position.y + (size.y / 2));
	}
}
