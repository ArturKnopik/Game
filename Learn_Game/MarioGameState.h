#pragma once
#include "GameState.h"
#include "Mario_MarioGameobject.h"
#include "Brick.h"
#include "Mario_LevelController.h"
class MarioGameState
	: public GameState
{
	std::shared_ptr<Mario::MarioGameobject> player;
	//std::shared_ptr<Mario::MarioGameobject> other;
	std::shared_ptr<Brick> brick;
	sf::View view1;
	LevelController levelControler;
	std::shared_ptr<Mario::Level> level;
public:
	MarioGameState() = delete;
	MarioGameState(std::shared_ptr<Game> game);

	void draw();
	void update(const double dt);
	void input();

	~MarioGameState();
};

