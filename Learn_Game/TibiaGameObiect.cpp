#include "TibiaGameObiect.h"

TGC::GameObiect::GameObiect()
{
	uid = UtilityTools::UniqueIDGenerator::getInstance().next();
	
}

void TGC::GameObiect::update(const double dt)
{

}

sf::Vector2<size_t> TGC::GameObiect::getPosition() const
{
	return position;
}
void TGC::GameObiect::setPosition(sf::Vector2<size_t> newPosition)
{

	position = newPosition;
}

size_t TGC::GameObiect::getID()
{
	return uid;
}

void TGC::GameObiect::setTexture(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
}

void TGC::GameObiect::renderDebug(sf::RenderWindow& renderWindow)
{
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::White);
	rect.setPosition(sf::Vector2f(static_cast<double>(position.x) * 32, static_cast<double>(position.y) * 32));
	rect.setSize(sf::Vector2f(32, 32));
	renderWindow.draw(rect);
	draw(renderWindow);
}

void TGC::GameObiect::draw(sf::RenderWindow& renderWindow)
{

}
