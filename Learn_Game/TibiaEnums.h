#pragma once
namespace TGC
{
	namespace ENUMS
	{
		enum Direction
		{
			UP = 1,
			DOWN = 2,
			LEFT = 3,
			RIGHT = 4,
			NONE = 5
		};
		enum Type
		{
			CREATURE,
			ITEM,
			GROUND
		};

		enum CombatType
		{
			PHYSICAL = 0,
			FIRE = 1,
			EARTH = 2,
			ICE = 3,
			ENERGY = 4,
			HEALING = 5,

			COMBATTYPESIZE = HEALING
		};
	}
}

