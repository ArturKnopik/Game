#pragma once
#include <stdint.h>
#include <chrono>
#include <string>
#include "TibiaEnums.h"
#include "SFML/Graphics/Color.hpp"
namespace TGC
{
	namespace UtilityTools
	{
		class UniqueIDGenerator
		{
		public:
			static UniqueIDGenerator& getInstance()
			{
				static UniqueIDGenerator Generator;
				return Generator;
			};
			size_t next();
		private:
			UniqueIDGenerator();
			size_t id;
		};
		/*
		sf::Color getColor(TGC::ENUMS::Color color, sf::Uint8 alpha=255)
		{ 
			switch (color)
			{
			case TGC::ENUMS::RED:
				return sf::Color(255,0,0, alpha);
				break;
			case TGC::ENUMS::GREEN:
				return sf::Color(0, 255, 0, alpha);
				break;
			case TGC::ENUMS::BLUE:
				return sf::Color(0, 0, 255, alpha);
				break;
			case TGC::ENUMS::YELLOW:
				return sf::Color(255, 140, 0, alpha);
				break;
			case TGC::ENUMS::PINK:
				return sf::Color(255, 255, 0, alpha);
				break;
			case TGC::ENUMS::WHITE:
				return sf::Color(255, 255, 255, alpha);
				break;
			case TGC::ENUMS::GREY:
				return sf::Color(128, 128, 128, alpha);
				break;
			case TGC::ENUMS::BLACK:
				return sf::Color(0, 0, 0, alpha);
				break;
			default:
				return sf::Color();
				break;
			}
			
		}
*/




	}
}
/*
int64_t getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
*/

