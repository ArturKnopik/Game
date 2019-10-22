#include "TibiaItemLoader.h"
#include "tinyxml.h"
#include "TibiaEnums.h"

void TGC::ItemPrefab::setName(std::string name)
{
	this->name = name;
}

void TGC::ItemPrefab::setPickable(bool pickupable)
{
	this->pickupable = pickupable;
}

void TGC::ItemPrefab::setUsable(bool useable)
{
	this->useable = useable;
}

void TGC::ItemPrefab::setMovable(bool moveable)
{
	this->moveable = moveable;
}

void TGC::ItemPrefab::setDecaing(bool decaing)
{
	this->decaying = decaing;
}

void TGC::ItemPrefab::setDecayTo(size_t decayTo)
{
	this->decayTo = decayTo;
}

void TGC::ItemPrefab::setAttack(unsigned short attack)
{
	this->attack = attack;
}

void TGC::ItemPrefab::setDeffence(unsigned short deffence)
{
	this->deffence = deffence;
}

void TGC::ItemPrefab::setItemSlot(TGC::ENUMS::ItemSlot slotType)
{
	this->slotType = slotType;
}

void TGC::ItemPrefab::setTexture(std::string texture)
{
	this->texture = texture;
}

TGC::ItemLoader::ItemLoader()
{
	loadFromFile();
}

std::unordered_map<int, TGC::ItemPrefab>& TGC::ItemLoader::getItemList()
{
	return itemList;
}

TGC::ItemPrefab TGC::ItemLoader::getItemPrefabByID(size_t id)
{
	for (auto it = itemList.begin(); it != itemList.end(); it++)
	{
		if (it->first == id)
		{
			return it->second;
		}
	}
	ItemPrefab itemPrefab;
	return  itemPrefab;
}

void TGC::ItemLoader::loadFromFile()
{
	TiXmlDocument doc("./resource/XML/Tibia/items.xml");
	if (!doc.LoadFile())
	{
		std::cout << "error:items.xml" << std::endl;
		return;
	}

	TiXmlHandle docHandle(&doc);

	TiXmlElement* itemNode = docHandle.FirstChild("items").Child("item", 0).ToElement();

	while (itemNode)
	{
		ItemPrefab item;

		TiXmlElement* itemName = itemNode->FirstChildElement("name");

		if (NULL != itemName)
		{
			item.setName(itemName->GetText());
		}

		TiXmlElement* itemTexture = itemNode->FirstChildElement("texture");

		if (NULL != itemTexture)
		{
			item.setTexture(itemTexture->GetText());
		}

		TiXmlElement* itempickupable = itemNode->FirstChildElement("pickable");

		if (NULL != itempickupable)
		{
			if (std::string(itempickupable->GetText()) == "true")
			{
				item.setPickable(true);
			}
			else
			{
				item.setPickable(false);
			}
		}

		TiXmlElement* useable = itemNode->FirstChildElement("useable");

		if (NULL != useable)
		{
			if (std::string(useable->GetText()) == "true")
			{
				item.setPickable(true);
			}
			else
			{
				item.setPickable(false);
			}
		}

		TiXmlElement* moveable = itemNode->FirstChildElement("moveable");

		if (NULL != moveable)
		{
			if (std::string(moveable->GetText()) == "true")
			{
				std::cout << "set move T" << std::endl;
				item.setMovable(true);
			}
			else
			{
				std::cout << "set move F" << std::endl; 
				item.setMovable(false);
			}
		}

		TiXmlElement* decaying = itemNode->FirstChildElement("decaying");

		if (NULL != decaying)
		{
			if (std::string(decaying->GetText()) == "true")
			{
				item.setDecaing(true);
			}
			else
			{
				item.setDecaing(false);
			}
		}

		TiXmlElement* decayingTo = itemNode->FirstChildElement("decayingTo");

		if (NULL != decayingTo)
		{
			item.setPickable(std::stoi(decayingTo->GetText()));
		}

		TiXmlElement* attack = itemNode->FirstChildElement("attack");

		if (NULL != attack)
		{
			if (NULL != decayingTo)
			{
				item.setPickable(std::stoi(attack->GetText()));
			}
		}

		TiXmlElement* deffence = itemNode->FirstChildElement("deffence");

		if (NULL != deffence)
		{
			item.setAttack( std::stoi(deffence->GetText()));
		}

		TiXmlElement* slotType = itemNode->FirstChildElement("itemslot");

		if (NULL != slotType)
		{
			if (std::string(slotType->GetText()) == "head")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::HEAD);
			}
			else if (std::string(slotType->GetText()) == "armor")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::ARMOR);
			}
			else if (std::string(slotType->GetText()) == "legs")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::LEGS);
			}
			else if (std::string(slotType->GetText()) == "boots")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::BOOTS);
			}
			else if (std::string(slotType->GetText()) == "weapon")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::WEAPON);
			}
			else if (std::string(slotType->GetText()) == "shield")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::SHIELD);
			}
			else if (std::string(slotType->GetText()) == "none")
			{
				item.setItemSlot(TGC::ENUMS::ItemSlot::NOEQUPIMENT);

			}
		}
		itemList.insert({ this->itemID, item });
		itemID++;

		itemNode = itemNode->NextSiblingElement("item");

	}
}
