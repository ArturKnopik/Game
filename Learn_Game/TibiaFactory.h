#pragma once
#include <memory>
#include <string>
namespace TGC
{

	class Creature;
	class Particle;
	class GameObiect;


	class Factory
	{
	public:
		Factory();
		std::shared_ptr<TGC::Creature> getMonster(std::string monsterName);
		std::shared_ptr<TGC::Particle> getParticle(std::string particleName);
		//std::shared_ptr<TGC::GameObiect> getGameObiect(std::string gameObioectName);

	};
}

