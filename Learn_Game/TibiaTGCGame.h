#pragma once

#include <memory>
#include <random>
#include <list>
#include <utility>

#include "Enums.h"
#include "TibiaMapCell.h"
#include "TibiaGameobject.h"
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
			std::shared_ptr<TGC::World> worldPRT;
			std::vector<std::pair<Creature*, TGC::ENUMS::Direction>> moveRequest;
			std::vector<TGC::Combatobject> combatRequest;
			std::vector<std::unique_ptr<TGC::Particle>> particleList;
			sf::RenderWindow* window;
			Factory factory;

			////////////////////////////////////////////////////////////
			/// \brief TGCGame copy c-tor delete, don't allow copy 'engine'.
			///
			////////////////////////////////////////////////////////////
			TGCGame(const TGCGame&) = delete;

			////////////////////////////////////////////////////////////
			/// \brief TGCGame c-tor  main class(singleton), initialize world, create monsters and other game stuff (mainly use to test things)
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

			////////////////////////////////////////////////////////////
			/// \brief check if pointer to creature(raw pointer) point to exist object
			///
			////////////////////////////////////////////////////////////
			bool isPlayerExits(TGC::Creature* creature);

			////////////////////////////////////////////////////////////
			/// \brief check if pointer to target(smart pointer) point to exist object
			///
			////////////////////////////////////////////////////////////
			bool isTargetExist(std::shared_ptr<TGC::Creature> target);

			////////////////////////////////////////////////////////////
			/// \brief check if pointer to creature(raw pointer) and pointer to target(smart pointer) are the same object, return true if id is the same
			///
			////////////////////////////////////////////////////////////
			bool isSameObjectUID(TGC::Creature* creature, std::shared_ptr<TGC::Creature> target);

			////////////////////////////////////////////////////////////
			/// \brief check if pointer to creature(raw pointer) and pointer to target(smart pointer) are the same object, return true if id is the same
			///
			////////////////////////////////////////////////////////////
			void resolveCombat();

			////////////////////////////////////////////////////////////
			/// \brief update particle lifetime and remove it if they end they life
			///
			////////////////////////////////////////////////////////////
			void updateParticle(const double dt);

			////////////////////////////////////////////////////////////
			/// \brief Draw particle
			///
			////////////////////////////////////////////////////////////
			void drawParticles(sf::RenderWindow& window);


			////////////////////////////////////////////////////////////
			/// \brief methd responible for resorve single collsion request, object move only if they can(if is free creature slot on target cell)
			///
			////////////////////////////////////////////////////////////
			void ResolveSingleMoveRequest(TGC::Creature* creature, TGC::ENUMS::Direction dir);

			void executeMoveScripts(Creature * creature, std::shared_ptr<TGC::MapCell> targetMapCell);
		public:
			static TGCGame& getSingleton();
			void setWindow(sf::RenderWindow& window);
			sf::RenderWindow& getWindow();
			~TGCGame() = default;
			void updateWorld(const double dt, std::shared_ptr<Gameobject> player);
			void draw(sf::RenderWindow& window);
			std::shared_ptr<Creature> getPlayer() { return player; }
			void addMoveRequest(Creature* creature, TGC::ENUMS::Direction dir);
			bool checkIfCellIsPossibleToMakeAMove(std::shared_ptr<TGC::MapCell> destinyCell);
			void input(sf::Event& event);
			bool isEndAnimationTimeReached();
			template <typename T>
			static T generateRandomNumber(T min, T max);
			void addCombatobject(TGC::Combatobject combatObj);
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