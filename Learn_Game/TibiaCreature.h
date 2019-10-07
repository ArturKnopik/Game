#pragma once
#include "TibiaEnums.h"
#include "TibiaGameObiect.h"

namespace TGC
{

	struct CreaturePrefab
	{
		std::string name = "Sample name";
		unsigned int hp = 100;
		unsigned walkingTime = 1.0;
	};
	namespace Camera
	{
		class CameraController;
	}

	namespace Global
	{
		class TGCGame;
	}
	class Creature : public GameObiect
	{
	protected:

		bool walkAnimation = false;
		double walkingTime = 1.0;
		double currentWalikingTime = walkingTime;
		std::string name = "placeHolder";
		TGC::ENUMS::Direction direction = TGC::ENUMS::Direction::DOWN;
		sf::Vector2<std::size_t> spriteOfset;
	protected:
		TGC::ENUMS::Direction* getDirection();
		TGC::Animation animationUp;
		TGC::Animation animationDown;
		TGC::Animation animationLeft;
		TGC::Animation animationRight;
		void calculateSpriteOfsetPercentDone();
		void applySpriteOfset();
		bool spriteMoving = true;
		bool isSpriteMoving();
		void setName(std::string name);
		void setWalkingTime(double time);
		void setAnimation(TGC::ENUMS::Direction animationDir, TGC::Animation animation);
	public:
		Creature();
		Creature* getCreature();
		Creature& getReferenceThis();
		virtual const std::string& getName() const;
		void sendMoveRequest(TGC::ENUMS::Direction dir);
		bool canWalk();
		virtual void update(const float dt);
		bool canPlayWalikngAnimation();
		void setWalkingAnimation(bool walkAnim, TGC::ENUMS::Direction direction); // idk how name this function
		void setDirection(TGC::ENUMS::Direction dir);
		virtual void draw(sf::RenderWindow& renderWindow) override;
		void setSpriteMoving(bool spriteMoving);
		void restartWalkingTime(bool canWalk);

		//TODO: Remove this function when create normal obiect
		virtual void renderDebug(sf::RenderWindow& renderWindow) override
		{
			draw(renderWindow);

			sf::RectangleShape rect;
			rect.setFillColor(sf::Color(100, 100, 100, 100));
			rect.setPosition(sf::Vector2f(static_cast<float>(position.x * 32 + 2), static_cast<float>(position.y * 32 + 2)));
			rect.setSize(sf::Vector2f(28, 28));
			renderWindow.draw(rect);
		}
		//friend class Global::TGCGame;
		friend class Camera::CameraController;
	};
}