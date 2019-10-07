#pragma once
#include "Creature.h"
#include <SFML/Graphics/View.hpp>

namespace TCG
{
	namespace Camera
	{
		class CameraController
		{
			std::shared_ptr<TGC::GameObiect> centerObiect;
			sf::View viewObj;
			sf::RenderWindow* windowPRT;
		public:
			CameraController();
			CameraController(std::shared_ptr<Creature> target, sf::RenderWindow& window);
			~CameraController() = default;
			void updateCamera(std::shared_ptr<Creature> target);
			sf::View& getViewe() { return viewObj; }
		};
	}
}

