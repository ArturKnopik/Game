#pragma once
#include "GameState.h"
#include "Button.h"

class GameListState :
	public GameState
{
	std::vector<std::unique_ptr<Button>> gameListButtons;
	int currentMarkedGame;
public:
	GameListState() = delete;
	GameListState(std::shared_ptr<Game> game);
	void draw();
	void update(const float dt);
	void input();
	virtual ~GameListState()=default;
};

