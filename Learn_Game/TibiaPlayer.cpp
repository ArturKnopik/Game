#include "TibiaPlayer.h"
#include "TibiaTGCGame.h"
#include "TibiaFrame.h"
#include "TibiaResoureManager.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

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

void TGC::Player::input(sf::RenderWindow& renderWindow)
{
	if (canWalk())
	{
		// mouse click events
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

		// mouse click events
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			drawCurrentCellMarkRectangle(renderWindow);
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			doThingWithTargetCell();
		}
	}
}

void TGC::Player::doThingWithTargetCell()
{

	sf::Vector2f worldPos = TGC::Global::TGCGame::getSingleton().getWindow().mapPixelToCoords(
									sf::Vector2i(sf::Mouse::getPosition(TGC::Global::TGCGame::getSingleton().getWindow()).x,
									             sf::Mouse::getPosition(TGC::Global::TGCGame::getSingleton().getWindow()).y));
	if (worldPos.x < 0 || worldPos.y < 0)
	{
		return;
	}
	sf::Vector2i worldPosInt = sf::Vector2i((worldPos.x / Setting::Const::cellSizeX), (worldPos.y / Setting::Const::cellSizeY));

	
	auto targetCell = TGC::Global::TGCGame::getSingleton().getXYCoordinateCell(worldPosInt.x, worldPosInt.y);

	if (targetCell->getCreature())
	{
		if (targetCreature==targetCell->getCreature())
		{
			targetCreature = nullptr;
		}
		else
		{
			targetCreature = targetCell->getCreature();
		}
		return;
	}

	/*
	//TODO: implemet use item in cell;
	*/



}

void TGC::Player::drawCurrentCellMarkRectangle(sf::RenderWindow& renderWindow)
{
	
	sf::Vector2f worldPos = renderWindow.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(renderWindow).x, sf::Mouse::getPosition(renderWindow).y));
	if (worldPos.x<0 || worldPos.y < 0)
	{
		return;
	}
	sf::Vector2i worldPosInt = sf::Vector2i((worldPos.x/ Setting::Const::cellSizeX), (worldPos.y/ Setting::Const::cellSizeY));
	
	
	sf::RectangleShape rect;
	
	rect.setPosition(worldPosInt.x * Setting::Const::cellSizeX, worldPosInt.y * Setting::Const::cellSizeY);
	rect.setSize(sf::Vector2f(Setting::Const::cellSizeX, Setting::Const::cellSizeY));
	int rectOutlineThickness = 1;
	rect.setOutlineThickness(rectOutlineThickness);
	rect.setFillColor(sf::Color(0, 0, 0, 0));
	rect.setOutlineColor(sf::Color(100,30,60,130));
	renderWindow.draw(rect);

}

void TGC::Player::drawCurrentTargetMarkRectangle(sf::RenderWindow& renderWindow)
{
	//TODO: Improve drawing target rect
	if (!targetCreature)
	{
		return;
	}

	sf::Vector2f creaturePos =static_cast<sf::Vector2f>( targetCreature->getPosition());
	if (creaturePos.x < 0 || creaturePos.y < 0)
	{
		return;
	}
	sf::Vector2i worldPosInt = sf::Vector2i(creaturePos.x , creaturePos.y );


	sf::RectangleShape rect;

	rect.setPosition(worldPosInt.x * Setting::Const::cellSizeX, worldPosInt.y * Setting::Const::cellSizeY);
	rect.setSize(sf::Vector2f(Setting::Const::cellSizeX, Setting::Const::cellSizeY));
	int rectOutlineThickness = 1;
	rect.setOutlineThickness(rectOutlineThickness);
	rect.setFillColor(sf::Color(0, 0, 0, 0));
	rect.setOutlineColor(sf::Color::Red);
	renderWindow.draw(rect);

}
