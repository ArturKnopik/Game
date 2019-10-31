#pragma once
#include "TibiaEnums.h"
#include "TibiaGameobject.h"
#include "settings.h"
#include "TibiaMonsterLoader.h"
#include "TibiaCreatureController.h"
namespace TGC
{
	namespace Camera
	{
		class CameraController;
	}

	namespace Global
	{
		class TGCGame;
	}
	class Creature : public Gameobject
	{
	protected:
		short attackRange = 1;
		unsigned int maxHP = 300;
		unsigned int currentHP = 300;
		bool walkAnimation = false;
		double walkingTime = Setting::Const::timeToWalk;
		double currentWalikingTime = walkingTime;
		short absorbPercent[TGC::ENUMS::CombatType::COMBATTYPESIZE]{ 100 };


		std::pair<double, double> attackTimer = std::make_pair(0, Setting::Const::timeToAttack);
		std::string name = "placeHolder";
		TGC::ENUMS::Direction direction = TGC::ENUMS::Direction::DOWN;
		sf::Vector2<std::size_t> spriteOfset;
		TGC::ENUMS::Direction* getDirection();
		TGC::Animation animationUp;
		TGC::Animation animationDown;
		TGC::Animation animationLeft;
		TGC::Animation animationRight;

		std::shared_ptr<TGC::CreatureController> creatureController;
		void calculateSpriteOfsetPercentDone();
		void applySpriteOfset();
		bool spriteMoving = true;
		bool isSpriteMoving();
		void setName(std::string name);
		void setWalkingTime(double time);
		void setAnimation(TGC::ENUMS::Direction animationDir, TGC::Animation animation);
		std::shared_ptr<Creature> targetCreature;
		void drawHealthBar(sf::RenderWindow& renderWindow);
		void updateAttackTimer(const double dt);
		void restartAttackTimer();
		bool canAttack();
		bool isTargetInRange();
		Creature() = delete;
	public:
		Creature(MonsterPrefab prfab);
		Creature* getCreature();
		Creature& getReferenceThis();
		virtual const std::string& getName() const;
		void sendMoveRequest(TGC::ENUMS::Direction dir);
		bool canWalk();
		virtual void update(const double dt) override;
		bool canPlayWalikngAnimation();
		void setWalkingAnimation(bool walkAnim, TGC::ENUMS::Direction direction); // idk how name this function
		void setDirection(TGC::ENUMS::Direction dir);
		virtual void draw(sf::RenderWindow& renderWindow) override;
		void setSpriteMoving(bool spriteMoving);
		void restartWalkingTime(bool canWalk);
		void setTarget(std::shared_ptr<Creature> creature);
		const std::shared_ptr<TGC::Creature> getTarget() const;
		void setHealth(unsigned int health);
		unsigned int getHealth();
		void setMaxHeatlh(unsigned int health);
		unsigned int getMaxHealth();
		void addHealth(unsigned int health);
		void removeHealth(unsigned int health);
		virtual void findTarget();
		short getAbsorbValue(TGC::ENUMS::CombatType combatType);
		void applyPrefabData(	MonsterPrefab prefab);

		friend class TGC::CreatureController;
		friend class Camera::CameraController;
	};
}