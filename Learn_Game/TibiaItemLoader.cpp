#include "TibiaItemLoader.h"
#include "TibiaEnums.h"
#include "TibiaUtilityTools.h"

#include <iostream>

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
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("./resource/XML/Tibia/items.xml");
	if (!result) {
		std::cout << "error:items.xml" << std::endl;
		return;
	}
	for (auto itemNode : doc.child("items").children())
	{
		pugi::xml_attribute idAttribute = itemNode.attribute("id");
		if (idAttribute)
		{
			parseItemNode(itemNode, idAttribute.as_int());
			continue;
		}
	}
}



void TGC::ItemLoader::parseItemNode(const pugi::xml_node& itemNode, size_t itemID)
{
	using namespace TGC::UtilityTools;
	ItemPrefab it;
	pugi::xml_attribute nameAttribute = itemNode.attribute("name");
	if (nameAttribute) {
		it.setName(itemNode.attribute("name").as_string());
	}
	else
	{
		it.setName(std::to_string(itemID));
	}

	pugi::xml_attribute textureAttribute = itemNode.attribute("texture");
	if (textureAttribute) {
		it.setTexture(textureAttribute.as_string());
	}


	for (auto attributeNode : itemNode.children())
	{
		pugi::xml_attribute keyAttribute = attributeNode.attribute("key");
		if (!keyAttribute) {
			continue;
		}
		std::string tmpStrValue = asLowerCaseString(std::string(keyAttribute.as_string()));


		if (tmpStrValue == "pickupable")
		{
			pugi::xml_attribute valuePickableAttribute = attributeNode.attribute("value");
			if (!valuePickableAttribute) {
				continue;
			}
			auto tempValue = std::string(valuePickableAttribute.as_string());
			if (tempValue == "true" || tempValue == "false")
			{
				if (tempValue == "true")
				{
					it.setPickable(true);
				}
				else
				{
					it.setPickable(false);
				}
			}
		}

		if (tmpStrValue == "useable")
		{
			pugi::xml_attribute valueUseableAttribute = attributeNode.attribute("value");
			if (!valueUseableAttribute) {
				continue;
			}
			auto tempValue = std::string(valueUseableAttribute.as_string());
			if (tempValue == "true" || tempValue == "false")
			{
				if (tempValue == "true")
				{
					it.setUsable(true);
				}
				else
				{
					it.setUsable(false);
				}
				continue;
			}
		}

		if (tmpStrValue == "moveable")
		{
			pugi::xml_attribute valueMoveableAttribute = attributeNode.attribute("value");
			if (!valueMoveableAttribute) {
				continue;
			}
			auto tempValue = std::string(valueMoveableAttribute.as_string());
			if (tempValue == "true" || tempValue == "false")
			{
			
				if (tempValue == "true")
				{	
					it.setMovable(true);
				}
				else
				{
					it.setMovable(false);
				}
				continue;
			}
		}

		if (tmpStrValue == "decaying")
		{
			pugi::xml_attribute valueDecayingAttribute = attributeNode.attribute("value");
			if (!valueDecayingAttribute) {
				continue;
			}
			auto tempValue = std::string(valueDecayingAttribute.as_string());
			if (tempValue == "true" || tempValue == "false")
			{
				if (tempValue == "true")
				{
					it.setDecaing(true);
				}
				else
				{
					it.setDecaing(false);
				}
				continue;
			}
		}

		if (tmpStrValue == "decayto")
		{
			pugi::xml_attribute valueDecayToAttribute = attributeNode.attribute("value");
			if (!valueDecayToAttribute) {
				continue;
			}
			auto tempValue = valueDecayToAttribute.as_ullong();
			it.setDecayTo(tempValue);
			continue;		
		}

		if (tmpStrValue == "attack")
		{
			pugi::xml_attribute valueAttackAttribute = attributeNode.attribute("value");
			if (!valueAttackAttribute) {
				continue;
			}
			auto tempValue = valueAttackAttribute.as_ullong();
			it.setAttack(tempValue);
			continue;
		}

		if (tmpStrValue == "deffence")
		{
			pugi::xml_attribute valueDeffenceAttribute = attributeNode.attribute("value");
			if (!valueDeffenceAttribute) {
				continue;
			}
			auto tempValue = valueDeffenceAttribute.as_ullong();
			it.setDeffence(tempValue);
			continue;
		}

		if (tmpStrValue == "slottype")
		{
			pugi::xml_attribute valueSlotTypeAttribute = attributeNode.attribute("value");
			if (!valueSlotTypeAttribute) {
				continue;
			}
			auto tempValue = std::string(valueSlotTypeAttribute.as_string());
			if (tempValue == "slot_none")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::NOEQUPIMENT);
			}
			else if (tempValue == "slot_head")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::HEAD);
			}
			else if (tempValue == "slot_armor")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::ARMOR);
			}
			else if (tempValue == "slot_legs")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::LEGS);
			}
			else if (tempValue == "slot_boots")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::BOOTS);
			}
			else if (tempValue == "slot_weapon")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::WEAPON);
			}
			else if (tempValue == "slot_shield")
			{
				it.setItemSlot(TGC::ENUMS::ItemSlot::SHIELD);
			}		
			continue;
		}

	}
	itemList.insert({ itemID, it });
}
