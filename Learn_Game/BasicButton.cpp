
#include "BasicButton.h"
BasicButton::BasicButton(std::string text, double x, double y, double width, double height, int textSize, std::shared_ptr<sf::Texture> texture)
	:Button(x,y,width,height),text(text), textSize(textSize), texture(texture)
{
	dType = drawType::TEXTURED_RECT;
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(textSize);
	textCoordinates.x = position.x + ((size.x - buttonText.getLocalBounds().width) / 2);
	textCoordinates.y = position.y + ((size.y - buttonText.getLocalBounds().height) / 2) - buttonText.getLocalBounds().height / 3;
}
BasicButton::BasicButton(std::string text, sf::Vector2f position, sf::Vector2f size, int textSize, std::shared_ptr<sf::Texture> texture)
	:Button(position, size), text(text), textSize(textSize), texture(texture)
{
	dType = drawType::TEXTURED_RECT;
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(textSize);
	textCoordinates.x = position.x + ((size.x - buttonText.getLocalBounds().width) / 2);
	textCoordinates.y = position.y + ((size.y - buttonText.getLocalBounds().height) / 2) - buttonText.getLocalBounds().height / 3;
}
BasicButton::BasicButton(std::string text, double x, double y, double width, double height, int textSize, sf::Color innerColor, sf::Color outerColor)
	:Button(x, y, width, height), text(text), textSize(textSize), innerColor(innerColor), outerColor(outerColor)
{
	dType = drawType::COLORED_RECT;
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(textSize);
	textCoordinates.x = position.x + ((size.x - buttonText.getLocalBounds().width) / 2);
	textCoordinates.y = position.y + ((size.y - buttonText.getLocalBounds().height) / 2) - buttonText.getLocalBounds().height / 3;
}
BasicButton::BasicButton(std::string text, sf::Vector2f position, sf::Vector2f size, int textSize, sf::Color innerColor, sf::Color outerColor)
	:Button(position, size), text(text), textSize(textSize), innerColor(innerColor), outerColor(outerColor)
{
	dType = drawType::COLORED_RECT;
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(textSize);
	textCoordinates.x = position.x + ((size.x - buttonText.getLocalBounds().width) / 2);
	textCoordinates.y = position.y + ((size.y - buttonText.getLocalBounds().height) / 2) - buttonText.getLocalBounds().height / 3;
}
/*
BasicButton::BasicButton(std::string text, double x, double y, double width, double height, int textSize, sf::Texture *)
{
	positions.x = x;  x
	positions.y = y;  x
	positions.width = width;  x
	positions.height = height;  x
	positions.textSize = textSize;  x
	this->text = text;  x
	this->texture = texture; x
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(textSize);
}

BasicButton::BasicButton(std::string text, double x, double y, double width, double height, int textSize, sf::Color outerColor, sf::Color innerColor)
{
	positions.x = x;
	positions.y = y;
	positions.width = width;
	positions.height = height;
	positions.textSize = textSize;
	this->innerColor = innerColor;
	this->outerColor = outerColor;
	font.loadFromFile("resource/font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setString(text);
	this->text = text;
	buttonText.setCharacterSize(textSize);
	textX = positions.x + ((positions.width - buttonText.getLocalBounds().width) / 2);
	textY = positions.y + ((positions.height - buttonText.getLocalBounds().height) / 2) - buttonText.getLocalBounds().height / 3;
}

BasicButton::BasicButton(std::string text, double x, double y, double width, double height, int textSize, std::shared_ptr<sf::Texture> texture)
{
}
*/
BasicButton::~BasicButton()
{
}

void BasicButton::onClick()
{

}

void BasicButton::noActived()
{
	isButtonActive = false;
}

void BasicButton::Actived()
{
	isButtonActive = true;
}

void BasicButton::draw(std::shared_ptr<sf::RenderWindow> window)
{
	// TODO: fix text coordinates when there are small letters in the text
	switch (dType)
	{
	case drawType::COLORED_RECT:
		if (isButtonActive)
		{
			rect.setPosition(sf::Vector2f(position.x - 4, position.y - 4));
			rect.setSize(sf::Vector2f(size.x + 8, size.y + 8));
			rect.setFillColor(outerColor);
			window->draw(rect);

		}

		rect.setPosition(sf::Vector2f(position.x - 2, position.y - 2));
		rect.setSize(sf::Vector2f(size.x + 4, size.y + 4));
		rect.setFillColor(innerColor);

		//double tempX=((positions.width-buttonText.getGlobalBounds().width)/2)
		buttonText.setPosition(sf::Vector2f(textCoordinates.x, textCoordinates.y));
		buttonText.setFillColor(innerColor);
		// std::cout << "fix: " << ((position.x - buttonText.getGlobalBounds().height) / 2) << std::endl;

		/*
		menuText.setCharacterSize(30);
		menuText.setPosition(sf::Vector2f(120, 300));
		menuText.setString("Quit!");
		menuText.setFillColor(sf::Color::Black);
		*/

		window->draw(rect);
		window->draw(buttonText);

		break;
	case drawType::TEXTURED_RECT:
		// TODO: implement texture drawing
		break;
	}
	
}

bool BasicButton::isActived()
{
	return isButtonActive;
}

void BasicButton::update(const double dt)
{
}

