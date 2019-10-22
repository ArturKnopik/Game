#pragma once

#include <memory>
#include <random>
#include <list>
#include <utility>

#include "Enums.h"
#include "TibiaMapCell.h"
#include "TibiaGameObiect.h"
#include "TibiaCreature.h"
#include "TibiaWorld.h"
#include "TibiaGlobalAnimationTimer.h"
#include "TibiaPlayer.h"
#include "TibiaCombat.h"
#include "TibiaParticle.h"


namespace TGC
{
	namespace Global
	{
		class TGCGame
		{
			TGC::GlobalAnimationTimer globalAnimationTimer;
			std::shared_ptr<Player> player;
			TGC::World world;
			std::vector<std::pair<Creature*, TGC::ENUMS::Direction>> moveRequest;
			std::vector<TGC::CombatObiect> combatRequest;
			std::vector<std::unique_ptr<TGC::Particle>> particleList;
			sf::RenderWindow* window;
			Factory factory;

			////////////////////////////////////////////////////////////
			/// \brief TGCGame copy c-tor delete, don't allow copy 'engine'.
			///
			////////////////////////////////////////////////////////////
			TGCGame(const TGCGame&) = delete;

			////////////////////////////////////////////////////////////
			/// \brief TGCGame c-tor  main class(singleton), initialize world, create monsters and other game stuff
			///
			////////////////////////////////////////////////////////////
			TGCGame();

			////////////////////////////////////////////////////////////
			/// \brief methd responible for resorve sollision, obiec move only if they can(if is free creature slot on target cell)
			///
			////////////////////////////////////////////////////////////
			void resolveMoveRequest();

			////////////////////////////////////////////////////////////
			/// \brief check if pointer to creature(raw pointer) and pointer to target(smart pointer) they point to exist object
			///
			////////////////////////////////////////////////////////////
			bool isPlayerAndTargetExist(TGC::Creature* creature, std::shared_ptr<TGC::Creature> target);
			bool isPlayerExits(TGC::Creature* creature);
			bool isTargetExist(std::shared_ptr<TGC::Creature> target);
			bool isSameObjectUID(TGC::Creature* creature, std::shared_ptr<TGC::Creature> target);
			void resolveCombat();
			void updateParticle(const double dt);
			void drawParticles(sf::RenderWindow& window);
		public:
			static TGCGame& getSingleton();
			void setWindow(sf::RenderWindow& window);
			sf::RenderWindow& getWindow();
			~TGCGame() = default;
			void updateWorld(const double dt, std::shared_ptr<GameObiect> player);
			void draw(sf::RenderWindow& window);
			std::shared_ptr<Creature> getPlayer() { return player; }
			void addMoveRequest(Creature* creature, TGC::ENUMS::Direction dir);
			
			void input(sf::Event& event);
			bool isEndAnimationTimeReached();
			template <typename T>
			static T generateRandomNumber(T min, T max);
			void addCombatObiect(TGC::CombatObiect combatObj);
			std::shared_ptr<TGC::MapCell> getXYCoordinateCell(size_t x, size_t y);
			std::vector<std::vector<std::shared_ptr<MapCell>>> getLocalArea(size_t x, size_t y);
			void addParticle(std::unique_ptr<TGC::Particle> particle);
		};


		template<typename T>
		inline T TGCGame::generateRandomNumber(T min, T max)
		{
			 std::random_device randomDevice;
			 std::default_random_engine randEng(randomDevice());
			 std::uniform_int_distribution<T> uniform_dist(min, max);
			return uniform_dist(randEng);
		}

	}

}