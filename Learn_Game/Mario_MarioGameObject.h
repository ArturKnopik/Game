#pragma once
#include "Mario_Gameobject.h"
namespace Mario
{
	class MarioGameobject final:
		public Gameobject
	{
	private:
		std::shared_ptr<sf::Event> event;
	public:
		MarioGameobject() = delete;
		MarioGameobject(sf::Vector2f position, sf::Vector2f size);
		void update(const double dt);
		virtual ~MarioGameobject();
		void onCollision(std::shared_ptr<Mario::Gameobject> other);
	};
}
