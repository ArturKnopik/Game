#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
class Button
{
protected:
	sf::Vector2f position;
	sf::Vector2f size;
public:
	Button()=delete;
	Button(float x, float y, float width, float height );
	Button(sf::Vector2f position, sf::Vector2f size);
	virtual ~Button()=default;
	virtual void onClick() = 0;
	virtual void noActived() = 0;
	virtual void Actived() = 0;
	virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
	virtual void update(const float dt) = 0;
	virtual bool isActived() = 0;
};

