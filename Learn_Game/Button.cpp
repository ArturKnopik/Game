#include "Button.h"

Button::Button(double x, double y, double width, double height)
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

