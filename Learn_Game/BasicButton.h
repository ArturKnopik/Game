#pragma once

#include "Button.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class BasicButton :
	public Button
{
private:
	enum drawType
	{
		COLORED_RECT,
		TEXTURED_RECT
	};
	drawType dType;
	sf::Vector2f textCoordinates;
	int textSize;
	std::string text;
	bool isButtonActive = true;
	std::shared_ptr<sf::Texture> texture;
	sf::Color outerColor;
	sf::Color innerColor;
	sf::Font font;
	sf::Text buttonText;
	sf::RectangleShape rect;

public:

	sf::Vector2f positions;
	BasicButton(std::string text, double x, double y, double width, double height, int textSize, std::shared_ptr<sf::Texture> texture);
	BasicButton(std::string text, sf::Vector2f position, sf::Vector2f size, int textSize, std::shared_ptr<sf::Texture> texture);
	BasicButton(std::string text, double x, double y, double width, double height, int textSize, sf::Color innerColor, sf::Color outerColor);
	BasicButton(std::string text, sf::Vector2f position, sf::Vector2f size, int textSize, sf::Color innerColor, sf::Color outerColor);

	~BasicButton();
	void onClick();
	void noActived();
	void Actived();
	void draw(std::shared_ptr<sf::RenderWindow> window);
	bool isActived();
	void update(const double dt);

};