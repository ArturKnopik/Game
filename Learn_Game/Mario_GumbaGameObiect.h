#pragma once
#include "Mario_GameObiect.h"
namespace Mario
{
	class GumbaGameObiect
		:public Mario::GameObiect
		
	{
		enum Moving{MOVE_LEFT, MOVE_RIGHT};
		Moving moveDirrectio;
	public:
		GumbaGameObiect() = delete;
		GumbaGameObiect(sf::Vector2f position, sf::Vector2f size);
		~GumbaGameObiect()=default;
		void update(const double dt) override;
		void onCollision(std::shared_ptr<Mario::GameObiect> other);
	};
}

