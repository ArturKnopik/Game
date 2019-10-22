#pragma once
#include "TibiaGameObiect.h"
#include "TibiaEnums.h"
#include "TibiaItemLoader.h"

namespace TGC
{
	class Item 
		: public GameObiect
	{
		std::string name;
		bool pickupable = false;
		bool useable = false;
		bool moveable = false;
		bool decaying = false;
		size_t decayTo = 0;
		unsigned short attack = 0;
		unsigned short deffence = 0;
		TGC::ENUMS::ItemSlot slotType = TGC::ENUMS::ItemSlot::NOEQUPIMENT;
		Item()= delete;
		TGC::Animation animation;
		
	public:
		
		Item(ItemPrefab itemprefab);
		void setName(std::string name);
		void setPickable(bool pickable);
		void setUseable(bool useable);
		void setMoveable(bool moveable);
		void setDecaying(bool decaynig);
		void setDacayingTarget(size_t decayToItem);
		void setSlotType(TGC::ENUMS::ItemSlot slotType);

		const bool isPickable() const;
		const bool isUsable() const;
		const bool isMoveable() const;
		const bool isDecayning() const;
		const TGC::ENUMS::ItemSlot getSlotType() const;
		const std::string getName() const;
		
		void applyPrefabData(ItemPrefab itemPrefab);
		virtual void draw(sf::RenderWindow& renderWindow) override;
	};
}

