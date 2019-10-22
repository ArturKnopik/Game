#pragma once
#include <string>
#include <unordered_map>
#include "TibiaEnums.h"

namespace TGC
{
	class ItemPrefab
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
		std::string texture;
	public:
		ItemPrefab() = default;
		void setName(std::string name);
		void setPickable(bool pickupable);
		void setUsable(bool usable);
		void setMovable(bool movable);
		void setDecaing(bool decaing);
		void setDecayTo(size_t decayTo);
		void setAttack(unsigned short attack);
		void setDeffence(unsigned short deffence);
		void setItemSlot(TGC::ENUMS::ItemSlot slotType);
		void setTexture(std::string texture);


		friend class Item;
		friend class Factory;
	};

	class ItemLoader
	{
		size_t itemID = 0;
		std::unordered_map<int, ItemPrefab> itemList;
		void loadFromFile();
	public:
		ItemLoader();
		std::unordered_map<int, ItemPrefab>& getItemList();
		ItemPrefab getItemPrefabByID(size_t id);


	};

}

