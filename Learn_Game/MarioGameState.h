#pragma once
#include "GameState.h"
#include "Mario_MarioGameObiect.h"
#include "Brick.h"
#include "Mario_LevelController.h"
class MarioGameState
	: public GameState
{
	std::shared_ptr<Mario::MarioGameObiect> player;
	//std::shared_ptr<Mario::MarioGameObiect> other;
	std::shared_ptr<Brick> brick;
	sf::View view1;
	LevelController levelControler;
	std::shared_ptr<Mario::Level> level;
public:
	MarioGameState() = delete;
	MarioGameState(std::shared_ptr<Game> game);

	void draw();
	void update(const float dt);
	void input();

	~MarioGameState();
};

