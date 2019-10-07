#include "TibiaPlayer.h"
#include "TibiaTGCGame.h"
#include "TibiaFrame.h"
#include "TibiaResoureManager.h"
#include "SFML/Window/Keyboard.hpp"

TGC::Player::Player()
{
	if (!animationControler)
	{
		animationControler.emplace(AnimationController());
	}
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/sample.png");
	TGC::ResoureManager::getInstance().getTextureHandler().addResource("sample", texture);
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/playerJMP.png");
	TGC::ResoureManager::getInstance().getTextureHandler().addResource("player", texture);
	animationUp.setTexture(TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName("player"));
	animationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	animationUp.addFrame(sf::IntRect(0, 96, 32, 32));
	animationUp.addFrame(sf::IntRect(64, 96, 32, 32));

	animationDown.setTexture(TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName("player"));
	animationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	animationDown.addFrame(sf::IntRect(0, 0, 32, 32));
	animationDown.addFrame(sf::IntRect(64, 0, 32, 32));

	animationLeft.setTexture(TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName("player"));
	animationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	animationLeft.addFrame(sf::IntRect(0, 32, 32, 32));
	animationLeft.addFrame(sf::IntRect(64, 32, 32, 32));

	animationRight.setTexture(TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName("player"));
	animationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	animationRight.addFrame(sf::IntRect(0, 64, 32, 32));
	animationRight.addFrame(sf::IntRect(64, 64, 32, 32));	
	animationControler->setAnimation(animationDown);
}

const sf::Vector2<size_t> TGC::Player::getSpritePosition() const
{
	return positionSprite;
}

void TGC::Player::input()
{
	if (canWalk())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sendMoveRequest(TGC::ENUMS::Direction::UP);
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sendMoveRequest(TGC::ENUMS::Direction::DOWN);
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sendMoveRequest(TGC::ENUMS::Direction::LEFT);
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sendMoveRequest(TGC::ENUMS::Direction::RIGHT);
			return;
		}
	}
}
