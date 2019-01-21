#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Arkanoid_Block.h"
#include "Arkanoid_Paddle.h"
#include "Arkanoid_Ball.h"
#include "Arkanoid_GameBoard.h"
#include "Arkanoid_BuffSystem.h"
#include "Arkanoid_PointSystem.h"
namespace Arkanoid
{
	class IDrawStyle
	{
		virtual void drawBlock(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>> & blockList)=0;
		virtual void drawPaddle(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Paddle & paddle) =0;
		virtual void drawBall(std::shared_ptr<sf::RenderWindow> window, const Arkanoid::Ball & ball)=0;
		virtual void drawBuffs(std::shared_ptr<sf::RenderWindow> window, Arkanoid::Buffs::BuffSystem & buffSystem) = 0;
		virtual void drawPoints(std::shared_ptr<sf::RenderWindow> window, Arkanoid::PointSystem & pointSystem)=0;
		//virtual void drawBuffs()=0;
	protected:
		Arkanoid::GameBoard playingField;
	public:
		IDrawStyle() = default;
		void setPlayingRect(Arkanoid::GameBoard & rect);
		virtual void draw(std::shared_ptr<sf::RenderWindow> window, const std::vector<std::shared_ptr<Arkanoid::Block>> & blockList, const Arkanoid::Paddle & paddle, Arkanoid::Ball & ball, 
							Arkanoid::Buffs::BuffSystem & buffSystem, Arkanoid::PointSystem & pointSystem)=0;
		virtual void update(const float dt) = 0;
		virtual ~IDrawStyle()=default;
	};
}
