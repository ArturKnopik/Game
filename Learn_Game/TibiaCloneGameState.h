#pragma once
#include "TibiaTGCGame.h"
#include "GameState.h"
#include "TibiaCameraController.h"
namespace TGC
{
	class TibiaCloneGameState : public GameState
	{
	private:
		Global::TGCGame* tcgGame;
		sf::Event event;
		Camera::CameraController camera;
	public:
		TibiaCloneGameState() = delete;
		TibiaCloneGameState(std::shared_ptr<Game> game);

		void draw();
		void update(const float dt);
		void input();

		~TibiaCloneGameState();
	};
}