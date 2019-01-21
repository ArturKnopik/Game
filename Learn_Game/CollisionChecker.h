#pragma once

#include <memory>
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace System
{
	template <class X, class Y>
	bool checkAABB(std::shared_ptr<X> leftEntity, std::shared_ptr<Y> rightDynamic);
	bool checkAABB(sf::Vector2f positionLeft, sf::Vector2f sizeLeft, sf::Vector2f positionRight, sf::Vector2f sizeRight);

}