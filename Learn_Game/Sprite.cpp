#include "Sprite.h"



kr::Sprite::Sprite()
{
	texture = std::shared_ptr<sf::Texture>(new sf::Texture);
	if (texture->loadFromFile("resource\\image\\sample.png")) {}
	sprite.setTexture(*texture);
	spriteType = STATIC;
}

kr::Sprite::Sprite(std::string url)
{
	texture = std::shared_ptr<sf::Texture>(new sf::Texture);
	if (texture->loadFromFile(url)) {}
	sprite.setTexture(*texture);
	spriteType = STATIC;
}
// ==========================================
// ==========================================
// ==========================================
// ==========================================

kr::Sprite::Sprite(std::string url, SpriteType spriteType)
{
	texture = std::shared_ptr<sf::Texture>(new sf::Texture);
	if (texture->loadFromFile(url)) {}
	this->spriteType = spriteType;
	switch(spriteType)
	{
	case STATIC:
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
		break;
	case STATIC_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});
		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	case ROTATEABLE_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(32, 32), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(32, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(64, 0), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(64, 32), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(64, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(96, 0), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(96, 32), sf::Vector2i(32, 32)),
															   sf::IntRect(sf::Vector2i(96, 64), sf::Vector2i(32, 32))});

		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	}
}

kr::Sprite::Sprite(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
	sprite.setTexture(*this->texture);
}

kr::Sprite::Sprite(std::shared_ptr<sf::Texture> texture, SpriteType spriteType)
{
	this->texture = texture;
	sprite.setTexture(*this->texture);
	this->spriteType = spriteType;
	switch (spriteType)
	{
	case STATIC:
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
		break;
	case STATIC_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});
		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	case ROTATEABLE_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(32, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(32, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(64, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(64, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(64, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(96, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(96, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(96, 64), sf::Vector2i(32, 32))});

		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	}
}

void kr::Sprite::setTexture(std::shared_ptr<sf::Texture> texture)
{
	this->texture = texture;
	sprite.setTexture(*this->texture);
	spriteType = STATIC;
}


void kr::Sprite::setTexture(std::shared_ptr<sf::Texture> texture, SpriteType spriteType)
{
	intRectSpriteMatrix.clear();

	this->texture = texture;
	sprite.setTexture(*this->texture);
	this->spriteType = spriteType;
	switch (spriteType)
	{
	case STATIC:
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
		break;
	case STATIC_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});
		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	case ROTATEABLE_ANIMATED:
		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(32, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(32, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(64, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(64, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(64, 64), sf::Vector2i(32, 32))});

		intRectSpriteMatrix.push_back(std::vector<sf::IntRect>{sf::IntRect(sf::Vector2i(96, 0), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(96, 32), sf::Vector2i(32, 32)),
			sf::IntRect(sf::Vector2i(96, 64), sf::Vector2i(32, 32))});

		sprite.setTextureRect(intRectSpriteMatrix[0][1]);
		break;
	}
}

void kr::Sprite::draw(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(sprite);
}

void kr::Sprite::setX(float x)
{
	sprite.setPosition(sf::Vector2f(x, sprite.getPosition().y));
}


void kr::Sprite::setY(float y)
{
	sprite.setPosition(sf::Vector2f(sprite.getPosition().x, y));
}

void kr::Sprite::setCurretTextureRect(const int col, const int row)
{
	switch (spriteType)
	{
	case STATIC_ANIMATED:
		if (row >= 0 && row <= 3)
		{
			sprite.setTextureRect(intRectSpriteMatrix[0][row]);
		}
		break;

	case ROTATEABLE_ANIMATED:
		if (row >= 0 && row <= 3 && col >= 0 && col <= 3)
		{
			sprite.setTextureRect(intRectSpriteMatrix[col][row]);
		}
		break;
	}
}

kr::Sprite::~Sprite()
{
	intRectSpriteMatrix.clear();
}
