#pragma once
#include "GameState.h"
#include "Mario_Player.h"
class MarioGameState
	: public GameState
{
	Mario::Player player;
public:
	MarioGameState() = delete;
	MarioGameState(std::shared_ptr<Game> game);

	void draw();
	void update(const float dt);
	void input();

	~MarioGameState();
};

