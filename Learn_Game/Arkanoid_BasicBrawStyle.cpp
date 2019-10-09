#include "Arkanoid_BasicBrawStyle.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics/Color.hpp>
void Arkanoid::BasicBrawStyle::drawBlock(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>>& blockList)
{
	double R = 0, G = 255;
	double colorJump = 255.0f / (blockList.size() + 1.0);
	for (auto it = blockList.begin(); it != blockList.end(); it++)
	{
		block.setPosition(sf::Vector2f((*it)->getPosition().x+1, (*it)->getPosition().y+1));
		block.setSize(sf::Vector2f((*it)->getSize().x-2, (*it)->getSize().y-2));
		block.setFillColor(sf::Color(R, G, 100,200+blockBreathingValue));
		if ((*it)->getCurrentLife() > 1)
		{
			block.setOutlineThickness(1);
		}
		else
		{
			block.setOutlineThickness(0);
		}
		window->draw(block);
		R = R + colorJump;
		G = G - colorJump;
	}
}
void Arkanoid::BasicBrawStyle::drawPaddle(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Paddle & paddle)
{
	this->paddleSprite.setPosition(paddle.getPosition());
	paddleSprite.setScale(sf::Vector2f(paddle.getSize().x/100, 1));
	this->paddle.setSize(paddle.getSize());
	this->paddle.setPosition(paddle.getPosition());
	
	window->draw(this->paddleSprite);
}
void Arkanoid::BasicBrawStyle::drawBall(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Ball & ball)
{
	circle.setFillColor(sf::Color::Green);
	circle.setRadius(ball.getRadius() - 1);
	this->circle.setPosition(ball.getPosition());
	window->draw(circle);
}

void Arkanoid::BasicBrawStyle::drawBuffs(std::shared_ptr<sf::RenderWindow> window, Arkanoid::Buffs::BuffSystem & buffSystem)
{
	sf::RectangleShape rectBackground;
	rectBackground.setPosition(sf::Vector2f(945, 245));
	rectBackground.setSize(sf::Vector2f(330, 800));
	rectBackground.setFillColor(sf::Color(255, 255, 255, 15));
	rectBackground.setOutlineColor(sf::Color(255, 255, 255, 50));
	rectBackground.setOutlineThickness(1);
	window->draw(rectBackground);
	circle.setFillColor(sf::Color::White);
		for (auto it = buffSystem.getBuffToCollect().begin(); it != buffSystem.getBuffToCollect().end(); it++)
		{
			//std::cout << "draw buffs" << std::endl;
			ballBuff.setRadius((*it)->getBall().getRadius()-1);
			ballBuff.setPosition((*it)->getPosition());
			window->draw(ballBuff);
		}

		sf::RectangleShape buffRect(sf::Vector2f(950, 200));
		buffRect.setSize(sf::Vector2f(320, 50));
		double yOffSet=250;  //start y to draw bufflist
		int currentBuffDrawed = 0;
		int maxBuffToDraw = 4;
		
		for (auto it = buffSystem.getBufflist().begin(); it != buffSystem.getBufflist().end(); it++)
		{
			buffRect.setPosition(950, yOffSet);
			if ((*it)->isBuffGood()==true )
			{
				buffRect.setFillColor(sf::Color::Green);

			}
			else
			{
				buffRect.setFillColor(sf::Color::Red);

			}
			window->draw(buffRect);
			buffName.setPosition(sf::Vector2f(960, yOffSet));

			switch ((*it)->getBuffType())
			{
			case Arkanoid::Buffs::Buff::BIG_PADDLE:
				buffName.setString("Big Paddle");
				break;
			case Arkanoid::Buffs::Buff::SMALL_PADDLE:
				buffName.setString("Small Paddle");
				break;
			case Arkanoid::Buffs::Buff::SPEED_BALL:
				buffName.setString("Fast Ball");
				break;
			case Arkanoid::Buffs::Buff::SLOW_BALL:
				buffName.setString("Slow Ball");
				break;
			case Arkanoid::Buffs::Buff::POINT_BUFF_MULTIPLER:
				buffName.setString("Multi Buff");
				break;
			default:
				buffName.setString("Buff");
				break;
			}
			buffName.setOutlineColor(sf::Color::Black);
			buffName.setOutlineThickness(1);
			window->draw(buffName);
			yOffSet += 60;
		}
}

void Arkanoid::BasicBrawStyle::drawPoints(std::shared_ptr<sf::RenderWindow> window, Arkanoid::PointSystem & pointSystem)
{
	points.setCharacterSize(60);
	std::stringstream sstring;
	sstring << pointSystem.getPoints();
	std::string string = sstring.str();
	points.setString(sstring.str());
	sstring.str("");
	sstring.clear();

	sstring<< pointSystem.getBasicMultipler();
	string ="x "+ sstring.str();
	//std::cout << "string1: " << sstring.str() << std::endl;
	if (pointSystem.getBuffMultipler() > 1)
	{
		sstring.str("");
		sstring.clear();
		sstring << pointSystem.getBuffMultipler();
		string =string + "*" +sstring.str();
		pointsMultipler.setFillColor(sf::Color(255,0,0));
	}
	else
	{
		pointsMultipler.setFillColor(sf::Color(255, 255, 255));
	}
	window->draw(points);
	pointsMultipler.setString(string);
	pointsMultipler.setPosition(sf::Vector2f(points.getPosition().x + points.getGlobalBounds().width+20, points.getPosition().y));
	window->draw(pointsMultipler);
}

Arkanoid::BasicBrawStyle::BasicBrawStyle()
	:lifeColorValue(0), lifeColorChangeValue(0.00003), blockBreathingChangeValue(0.00005), blockBreathingValue(0)
{
	
	if (!font.loadFromFile("resource/font/Arkanoid/8bitOperatorPlus8-Regular.ttf"))
	{
		std::cout << "eorr" << std::endl;
	}
	else
	{
		points.setPosition(sf::Vector2f(951, 80));
		points.setFont(font);
		points.setCharacterSize(60);

		pointsMultipler.setPosition(0, 0);
		pointsMultipler.setFont(font);
		pointsMultipler.setCharacterSize(40);

		buffName.setFont(font);
		points.setCharacterSize(30);

	}



	circle.setFillColor(sf::Color::Green);
	circle.setOutlineColor(sf::Color::White);
	circle.setOutlineThickness(1);
	block.setOutlineThickness(1);
	block.setOutlineColor(sf::Color::White);
	block.setPosition(20, 20);
	block.setSize(sf::Vector2f(900, 680));
	
	lostTexture.loadFromFile("resource/image/Arkanoid/Lost.png");
	lostSprite.setTexture(lostTexture);
	lostSprite.setPosition(950, 150);

	paddleTexture.loadFromFile("resource/image/Arkanoid/paddle.png");

	ballBuffTexture.loadFromFile("resource/image/Arkanoid/buffImage.png");
	ballBuff.setTexture(&ballBuffTexture);
	ballBuff.setOutlineThickness(1);
	ballBuff.setOutlineColor(sf::Color::White);
	ballBuff.setPointCount(5);

	paddleSprite.setTexture(paddleTexture);
	paddleSprite.setColor(sf::Color(255, 0, 0, 200));
	paddle.setTexture( paddleSprite.getTexture());
	paddleTexture.setSmooth(true);

}

void Arkanoid::BasicBrawStyle::draw(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>> & blockList, const Arkanoid::Paddle & paddle, Arkanoid::Ball & ball, Arkanoid::Buffs::BuffSystem & buffSystem, Arkanoid::PointSystem & pointSystem)
{
	sf::RectangleShape board;
	gameBoardRect.setPosition(playingField.getPosition().x, playingField.getPosition().y);
	gameBoardRect.setSize(sf::Vector2f(playingField.getSize().x+ball.getRadius()*2, playingField.getSize().y+ball.getRadius()*2));
	gameBoardRect.setFillColor(sf::Color(255, 255, 0, 10));
	gameBoardRect.setOutlineColor(sf::Color::White);
	gameBoardRect.setOutlineThickness(1);
	window->draw(gameBoardRect);

	// virtual functions draw
	drawBlock(window, blockList);
	drawBall(window, ball);
	drawPaddle(window, paddle);
	if (paddle.getCurrentLife() > 0)
	{
		drawBuffs(window, buffSystem);
	}
	drawPoints(window, pointSystem);
	// 


	sf::CircleShape lifeCircle;
	lifeCircle.setRadius(22);
	for (int i = 0; i < paddle.getCurrentLife(); i++)
	{
		lifeCircle.setPosition(playingField.getPosition().x + playingField.getSize().x + 60 + i * 50, 30);
		lifeCircle.setFillColor(sf::Color(60, 120+lifeColorValue, 180));
		window->draw(lifeCircle);
	}
	if (paddle.getCurrentLife() < 1)
	{
		window->draw(lostSprite);
	}
}

void Arkanoid::BasicBrawStyle::update(const double dt)
{
	if (lifeColorValue < 50 && lifeColorValue > -50)
	{
		lifeColorValue + lifeColorChangeValue;
	}
	else
	{
		lifeColorChangeValue = lifeColorChangeValue * -1;
	}
	lifeColorValue = lifeColorValue + lifeColorChangeValue * dt;
	
	if (blockBreathingValue < 30 && blockBreathingValue > -30)
	{
		blockBreathingValue + blockBreathingChangeValue;
	}
	else
	{
		blockBreathingChangeValue *= -1;
	}
	blockBreathingValue = blockBreathingValue + blockBreathingChangeValue * dt;
}

Arkanoid::BasicBrawStyle::~BasicBrawStyle()
{
}
