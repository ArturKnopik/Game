#pragma once
#include "TibiaGameobject.h"
namespace TGC
{
	class Particle
		: public Gameobject
	{
		bool isLive=true;
		std::pair<double, double> lifeTimer = std::make_pair(0.0,0.0);
		TGC::Animation particleAnimation;
	public:
		Particle()=delete;
		Particle(size_t x, size_t y, std::string textureName);
		Particle(std::string textureName);
		virtual void update(const float dt) ;
		virtual void draw(sf::RenderWindow& renderWindow) override;
		bool isDeath();
	};
}

