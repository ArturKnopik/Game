#pragma once
#include <vector>
#include "Arkanoid_IBuff.h"
#include "Arkanoid_BuffDrop.h"
#include "Arkanoid_GameBoard.h"
#include <memory>
#include <utility>
#include "Arkanoid_BuffFactory.h"

namespace Arkanoid
{
	namespace Buffs
	{
		class IBuff;
		class BuffDropBall;

		class BuffSystem
		{
			std::vector<std::shared_ptr<Arkanoid::Buffs::IBuff>> buffList;
			std::vector<std::shared_ptr<Arkanoid::Buffs::BuffDropBall>> buffToCollect;
		public:
			BuffSystem();
			void updateBuffs(const float dt);
			void updateDrop(const float dt, Arkanoid::GameBoard gameBoard);
			void addBuff(std::shared_ptr<Arkanoid::Buffs::IBuff> buff);
			void addBuffToCollect(sf::Vector2f position);
			void removeAllBuffs();
			std::vector<std::shared_ptr<Arkanoid::Buffs::IBuff>> & getBufflist();
			std::vector<std::shared_ptr<Arkanoid::Buffs::BuffDropBall>> & getBuffToCollect();
			~BuffSystem() = default;

		};
	}
}

