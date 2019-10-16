#pragma once
namespace TGC
{
	class Creature;

	class CreatureController
	{
	public:
		CreatureController() = default;
		virtual void updateDirection(Creature* creature);
	};
}

