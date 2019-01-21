#include "Button.h"

Button::Button(float x, float y, float width, float height)
{
	position.x = x;
	position.y = y;
	size.x = width;
	size.y = height;
}

Button::Button(sf::Vector2f position, sf::Vector2f size)
	:position(position), size(size)
{
}

