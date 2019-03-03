#pragma once
#include "Mario_GameObiect.h"
namespace Mario
{
	class MarioGameObiect final:
		public GameObiect
	{
	private:
		std::shared_ptr<sf::Event> event;
	public:
		MarioGameObiect() = delete;
		MarioGameObiect(sf::Vector2f position, sf::Vector2f size);
		void update(const float dt);
		virtual ~MarioGameObiect();
		void onCollision(std::shared_ptr<Mario::GameObiect> other);
	};
}
