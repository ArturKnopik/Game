#pragma once
#include "Arkanoid_IDrawStyle.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Arkanoid_BuffFactory.h"
#include "Arkanoid_BuffSystem.h"
#include "Arkanoid_Paddle.h"
#include "Arkanoid_Ball.h"
namespace Arkanoid
{
	class BasicBrawStyle :
		public Arkanoid::IDrawStyle
	{
		sf::RectangleShape gameBoardRect;
		sf::RectangleShape block;
		sf::CircleShape circle;
		sf::RectangleShape paddle;
		sf::RectangleShape lostRect;
		sf::CircleShape ballBuff;
		sf::Texture ballBuffTexture;
		sf::Texture lostTexture;
		sf::Sprite lostSprite;
		sf::Texture paddleTexture;
		sf::Sprite paddleSprite;
		sf::Font font;
		sf::Text points;
		sf::Text buffName;
		sf::Text pointsMultipler;
		double lifeColorValue;
		double lifeColorChangeValue;
		double blockBreathingValue;
		double blockBreathingChangeValue;
		void drawBlock(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>> & blockList);
		void drawPaddle(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Paddle & paddle);
		void drawBall(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Ball & ball);
		void drawBuffs(std::shared_ptr<sf::RenderWindow> window, Arkanoid::Buffs::BuffSystem & buffSystem);
		void drawPoints(std::shared_ptr<sf::RenderWindow> window, Arkanoid::PointSystem & pointSystem);
		//void drawBuffs();
	public:
		BasicBrawStyle();
		virtual void draw(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>> & blockList, const Arkanoid::Paddle & paddle, Arkanoid::Ball & ball, Arkanoid::Buffs::BuffSystem & buffSystem, Arkanoid::PointSystem & pointSystem);
		virtual void update(const double dt);
		virtual ~BasicBrawStyle();
	};
}

