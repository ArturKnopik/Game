#include "TibiaCreatureController.h"
#include "TibiaTGCGame.h"
void TGC::CreatureController::updateDirection(Creature* creature)
{
	if (creature)
	{
		if (creature->canWalk())
		{
			int newDir = TGC::Global::TGCGame::getSingleton().generateRandomNumber<int>(1, 4);

			switch (newDir)
			{
			case 1:
				creature->sendMoveRequest(TGC::ENUMS::Direction::UP);
				break;
			case 2:
				creature->sendMoveRequest(TGC::ENUMS::Direction::DOWN);
				break;
			case 3:
				creature->sendMoveRequest(TGC::ENUMS::Direction::LEFT);
				break;
			case 4:
				creature->sendMoveRequest(TGC::ENUMS::Direction::RIGHT);
				break;
			default:
				break;
			}

		}
	}
}
