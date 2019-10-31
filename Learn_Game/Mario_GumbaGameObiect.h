#pragma once
#include "Mario_Gameobject.h"
namespace Mario
{
	class GumbaGameobject
		:public Mario::Gameobject
		
	{
		enum Moving{MOVE_LEFT, MOVE_RIGHT};
		Moving moveDirrectio;
	public:
		GumbaGameobject() = delete;
		GumbaGameobject(sf::Vector2f position, sf::Vector2f size);
		~GumbaGameobject()=default;
		void update(const double dt) override;
		void onCollision(std::shared_ptr<Mario::Gameobject> other);
	};
}

