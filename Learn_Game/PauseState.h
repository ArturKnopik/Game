#pragma once
#include "GameState.h"
//#include "TestEnemy.h"
class PauseState :
	public GameState
{
private:
public:


	PauseState(std::shared_ptr<Game> game);
	~PauseState();
	void draw();
	void update(const float dt);
	void input();

};

