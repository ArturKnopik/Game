#include <random>
#include "TibiaTGCGame.h"
#include "TibiaResoureManager.h"
#include "TibiaRat.h"


TGC::Rat::Rat()
{
	if (!animationControler)
	{
		animationControler.emplace(AnimationController());
	}
	texture = std::make_shared<sf::Texture>();
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("resource/image/EnemyGraphic.png");
	ResoureManager::getInstance().getTextureHandler().addResource("testEnemy", texture);

	animationUp.setTexture(ResoureManager::getInstance().getTextureHandler().getResourceByName("testEnemy"));
	animationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	animationUp.addFrame(sf::IntRect(0, 96, 32, 32));
	animationUp.addFrame(sf::IntRect(64, 96, 32, 32));

	animationDown.setTexture(ResoureManager::getInstance().getTextureHandler().getResourceByName("testEnemy"));
	animationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	animationDown.addFrame(sf::IntRect(0, 0, 32, 32));
	animationDown.addFrame(sf::IntRect(64, 0, 32, 32));

	animationLeft.setTexture(ResoureManager::getInstance().getTextureHandler().getResourceByName("testEnemy"));
	animationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	animationLeft.addFrame(sf::IntRect(0, 32, 32, 32));
	animationLeft.addFrame(sf::IntRect(64, 32, 32, 32));

	animationRight.setTexture(ResoureManager::getInstance().getTextureHandler().getResourceByName("testEnemy"));
	animationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	animationRight.addFrame(sf::IntRect(0, 64, 32, 32));
	animationRight.addFrame(sf::IntRect(64, 64, 32, 32));
	animationControler->setAnimation(animationDown);
}

void TGC::Rat::update(const double dt)
{
	Creature::update(dt);
	if (canWalk())
	{
		int newDir = TGC::Global::TGCGame::getSingleton().generateRandomNumber<int>(1, 4);
		
		switch (newDir)
		{
		case 1:
			sendMoveRequest(TGC::ENUMS::Direction::UP);
			break;
		case 2:
			sendMoveRequest(TGC::ENUMS::Direction::DOWN);
			break;
		case 3: 
			sendMoveRequest(TGC::ENUMS::Direction::LEFT);
			break;
		case 4:
			sendMoveRequest(TGC::ENUMS::Direction::RIGHT);
			break;
		default:
			break;
		}
		
	}

}
