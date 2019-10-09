#pragma once
#include "GameState.h"
//#include "Arkanoid_Board.h"
#include "Arkanoid_Level.h"
#include "Arkanoid_IDrawStyle.h"
#include "Arkanoid_Paddle.h"
#include "Arkanoid_Ball.h"
#include "Arkanoid_GameBoard.h"
#include "Arkanoid_BuffFactory.h"
#include "Arkanoid_BuffSystem.h"
#include "Arkanoid_PointSystem.h"
class TetrisGameState :
	public GameState
{	
	Arkanoid::GameBoard playingField;
	std::shared_ptr<Arkanoid::Level> level;
	std::vector<std::shared_ptr<Arkanoid::Block>> blockList;
	std::shared_ptr<Arkanoid::IDrawStyle> drawStyle;
	Arkanoid::GameBoard gameBoard;
	Arkanoid::Paddle paddle;
	Arkanoid::Ball ball;
	Arkanoid::Buffs::BuffSystem buffSystem;
	Arkanoid::Buffs::BuffFactory buffFactory;
	Arkanoid::PointSystem pointSystem;
	//bool checkCollision(std::shared_ptr<Tetris::Block> block);
	bool checkCollision(sf::Vector2f position, sf::Vector2f size, const Arkanoid::Ball & ball);
	void calculateDirectionOfReflection(std::shared_ptr<Arkanoid::Block> block, Arkanoid::Ball & ball);
	std::shared_ptr<Arkanoid::Level>  level_t;
	void updateBuffs(const double dt);
public:
	TetrisGameState() = delete;
	TetrisGameState(std::shared_ptr<Game> game, std::shared_ptr<Arkanoid::IDrawStyle> drawStyle);
	~TetrisGameState()=default;
	void draw();
	void update(const double dt);
	void input();
	void loadLevel(std::shared_ptr<Arkanoid::Level> level);

};

