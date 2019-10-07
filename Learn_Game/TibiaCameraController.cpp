#include "TibiaCameraController.h"
#include <iostream>
#include "TibiaTGCGame.h"
#include "TibiaCreature.h"
#include "settings.h"
TGC::Camera::CameraController::CameraController()
	:windowPRT(nullptr)
{
}

TGC::Camera::CameraController::CameraController(std::shared_ptr<TGC::Creature> target, sf::RenderWindow & window)
	:windowPRT(&window)
{
	viewObj.setSize(WIDTH, HEIGHT);
	std::cout << "view size: " << viewObj.getSize().x << " : " << viewObj.getSize().y << std::endl;
	viewObj.zoom(0.5);
	//windowPRT->setView(viewe);
	//viewe.setViewport(sf::Vector2f(target->getPosition()), windowPRT->);
//	viewe.setCenter(sf::Vector2f(target->getPosition().x, target->getPosition().y));
//	viewe.setSize(sf::Vector2f(windowPRT->getSize().x, windowPRT->getSize().y));
//	viewe.setViewport(sf::FloatRect(target->getPosition().x, target->getPosition().y, windowPRT->getSize().y, windowPRT->getSize().y));
//	viewe.setCenter(sf::Vector2f(target->getPosition().x, target->getPosition().y));
}

void TGC::Camera::CameraController::updateCamera(std::shared_ptr<TGC::Creature> target)
{
	viewObj.setCenter(sf::Vector2f(static_cast<float>(target->positionSprite.x), static_cast<float>(target->positionSprite.y)));
}
