#include "ArkanoidPlayingGameState.h"
#include <memory>
#include "PauseState.h"
#include "Arkanoid_BasicBrawStyle.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Arkanoid_SpeedUpBallBuff.h"


TetrisGameState::TetrisGameState(std::shared_ptr<Game> game, std::shared_ptr<Arkanoid::IDrawStyle> drawStyle)
{
	level_t = std::shared_ptr<Arkanoid::Level>(new Arkanoid::Level());
	blockList = level_t->getBlockList();
	drawStyle->setPlayingRect(playingField);
	this->drawStyle = drawStyle;
	this->game = game;
	ball.setUpdateAble(false);
	paddle.setPosition(sf::Vector2f(playingField.getPosition().x + playingField.getSize().x / 2 - paddle.getSize().x / 2, playingField.getPosition().y + playingField.getSize().y - 4 * paddle.getSize().y));
}

bool TetrisGameState::checkCollision(sf::Vector2f position, sf::Vector2f size, const Arkanoid::Ball & ball)
{	
	double testX = ball.getPosition().x;
	double testY = ball.getPosition().y;
	if (ball.getPosition().x < position.x)
	{
		testX = position.x; 
	}

	else if (ball.getPosition().x > position.x + size.x)
	{
		testX = position.x + size.x;  
	}

	if (ball.getPosition().y < position.y)
	{
		testY = position.y;
	}
	
	else if (ball.getPosition().y > position.y + size.y)
	{
		testY = position.y + size.y;
	}

	double distX = ball.getPosition().x - testX;
	double distY = ball.getPosition().y - testY;
	double distance = sqrt((distX*distX) + (distY*distY));
	if (distance <= ball.getRadius()) 
	{
		return true;
	}
	return false;	
	

}

void TetrisGameState::calculateDirectionOfReflection(std::shared_ptr<Arkanoid::Block> block, Arkanoid::Ball & ball)
{
	// TODO: improving detection axis changes, currently looks good but not perfect, minor problems with collision detection on the corners of rectangles
	
	double ballBottom = ball.getPosition().y + ball.getRadius()*2;
	double blockBottom = block->getPosition().y + block->getSize().y;
	double ballRight = ball.getPosition().x + ball.getRadius()*2;
	double blockRight = block->getPosition().x + block->getSize().x;

	double bottomCollision = blockBottom - ball.getPosition().y;
	double topCollision = ballBottom - block->getPosition().y;
	double leftCollision = ballRight - block->getPosition().x;
	double rightCollision = blockRight - ball.getPosition().x;

	if (topCollision < bottomCollision && topCollision < leftCollision && topCollision < rightCollision)
	{
		//Top collision 
		ball.reverseYSpeed();
	}
	if (bottomCollision < topCollision && bottomCollision < leftCollision && bottomCollision < rightCollision)
	{
		//bottom collision
		ball.reverseYSpeed();
	}
	if (leftCollision < rightCollision && leftCollision < topCollision && leftCollision < bottomCollision)
	{
		//Left collision
		ball.reverseXSpeed();
	}
	if (rightCollision < leftCollision && rightCollision < topCollision && rightCollision < bottomCollision)
	{
		//Right collision
		ball.reverseXSpeed();
	}
}

void TetrisGameState::updateBuffs(const double dt)
{
	for (auto it = buffSystem.getBuffToCollect().begin(); it != buffSystem.getBuffToCollect().end(); it++)
	{
		if (checkCollision(paddle.getPosition(), paddle.getSize(), (*it)->getBall()))
		{
			switch ((*it)->getBuff())
			{
			case Arkanoid::Buffs::WhatToBuff::BALL:
				buffSystem.addBuff(buffFactory.getNewBuff(ball));
				break;
			case Arkanoid::Buffs::WhatToBuff::PADDLE:
				buffSystem.addBuff(buffFactory.getNewBuff(paddle));
				break;
			case Arkanoid::Buffs::WhatToBuff::POINTS:
				buffSystem.addBuff(buffFactory.getNewbuff(pointSystem));
				//buffSystem.addBuff(buffFactory.getNewBuff(pointSystem));
				break;
			default:
				break;
			}
			buffSystem.getBuffToCollect().erase(it);
			it--;
		}
	}

}

void TetrisGameState::draw()
{
	drawStyle->draw(game->window, blockList, paddle, ball, buffSystem, pointSystem);
	//paddle.draw(game->window);
}

void TetrisGameState::update(const double dt)
{
	if (paddle.getCurrentLife()>0)
	{
		paddle.update(dt);
	}
	if (paddle.getPosition().x < playingField.getPosition().x)
	{
		paddle.setPosition(sf::Vector2f(playingField.getPosition().x, paddle.getPosition().y));
	}
	if (paddle.getPosition().x + paddle.getSize().x > playingField.getPosition().x + playingField.getSize().x +ball.getRadius()*2)
	{
		paddle.setPosition(sf::Vector2f(playingField.getPosition().x + playingField.getSize().x - paddle.getSize().x + ball.getRadius()*2, paddle.getPosition().y));
	}
	if (ball.getUpdateAble())
	{
		ball.update(dt);
	}
	else
	{
		ball.setPosition(sf::Vector2f(paddle.getPosition().x + paddle.getSize().x/2 - ball.getRadius(), paddle.getPosition().y-ball.getRadius()*2));
	}
	
	for (auto it = blockList.begin(); it != blockList.end(); it++)
	{
		if (checkCollision((*it)->getPosition()-sf::Vector2f(ball.getRadius(), ball.getRadius()), (*it)->getSize(), ball))
		{
			(*it)->update(dt);
			(*it)->removeLife();
			calculateDirectionOfReflection((*it), ball);
			if ((*it)->getCurrentLife() <= 0)
			{
				if (rand()%3<1)
				{
					buffSystem.addBuffToCollect(sf::Vector2f((*it)->getPosition().x + (*it)->getSize().x / 2, (*it)->getPosition().y + (*it)->getSize().y));
				}
				blockList.erase(it);
				it--;
				pointSystem.addPoints(10);
				pointSystem.increaseBasicMultipler();
			}
		}
	}
	if (checkCollision(paddle.getPosition(), paddle.getSize(), ball))
	{
		ball.setHitAngle(paddle);
	}

	if (ball.getPosition().x < playingField.getPosition().x || ball.getPosition().x > playingField.getPosition().x + playingField.getSize().x)
	{
		ball.reverseXSpeed();
	}
	if (ball.getPosition().y < playingField.getPosition().y)
	{
		ball.reverseYSpeed();
	}
	if (ball.getPosition().y > playingField.getPosition().y + playingField.getSize().y)
	{
		buffSystem.removeAllBuffs();
		paddle.removeLife();
		ball.setUpdateAble(false);
		pointSystem.resetBasicMultipler();
		pointSystem.resetBuffMultipler();
	}

	if (blockList.begin() == blockList.end())
	{
		loadLevel(std::shared_ptr<Arkanoid::Level>(new Arkanoid::Level()));
	}
	drawStyle->update(dt);


	buffSystem.updateBuffs(dt);
	buffSystem.updateDrop(dt, gameBoard);
	updateBuffs(dt);
}

void TetrisGameState::input()
{
	while (game->window->pollEvent(*event)) {
		switch (event->type) {
		case sf::Event::Closed:
			game->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event->key.code == sf::Keyboard::Escape)
			{
				game->popState();
			}
			if (event->key.code == sf::Keyboard::R)
			{
				game->popState();
				game->pushState(std::unique_ptr<GameState>(new TetrisGameState(game, std::unique_ptr<Arkanoid::IDrawStyle>(new Arkanoid::BasicBrawStyle()))));
			}
			if (event->key.code == sf::Keyboard::Space)
			{
				if (paddle.getCurrentLife() > 0)
				{
					if (!ball.getUpdateAble())
					{
						ball.setHitAngle(paddle);
						ball.setUpdateAble(true);
						buffSystem.removeAllBuffs();
					}
					else
					{
						// TODO: implement shoot mechanic - buff system
					}
				}
			}
			if (event->key.code == sf::Keyboard::O)
			{
				buffSystem.addBuff(std::move(std::shared_ptr<Arkanoid::Buffs::IBuff>(buffFactory.getNewbuff(pointSystem))));
				// TODO:  Test KEY --- to remove when end this part of project
			}
		}
	}
	paddle.input(event);
}

void TetrisGameState::loadLevel(std::shared_ptr<Arkanoid::Level> level)
{
	blockList = level->getNextLevel()->getBlockList();
	ball.setUpdateAble(false);
	paddle.setPosition(sf::Vector2f(playingField.getPosition().x + playingField.getSize().x / 2 - paddle.getSize().x/2, playingField.getPosition().y + playingField.getSize().y - 4 * paddle.getSize().y));
}
