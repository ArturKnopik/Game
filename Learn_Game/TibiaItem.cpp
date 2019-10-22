#include "TibiaItem.h"
#include "TibiaResoureManager.h"
#include "settings.h"

TGC::Item::Item(ItemPrefab itemprefab)
{
	if (!animationControler)
	{
		animationControler.emplace(AnimationController());
	}
	applyPrefabData(itemprefab);

}


void TGC::Item::setName(std::string name)
{
	this->name = name;
}

void TGC::Item::setPickable(bool pickable)
{
	this->pickupable = pickable;
}

void TGC::Item::setUseable(bool useable)
{
	this->useable = useable;
}

void TGC::Item::setMoveable(bool moveable)
{
	this->moveable = moveable;
}

void TGC::Item::setDecaying(bool decaynig)
{
	this->decaying = decaying;
}

void TGC::Item::setDacayingTarget(size_t decayTo)
{
	this->decayTo = decayTo;
}

void TGC::Item::setSlotType(TGC::ENUMS::ItemSlot slotType)
{
	this->slotType = slotType;
}

const bool TGC::Item::isPickable() const
{
	return pickupable;
}

const bool TGC::Item::isUsable() const
{
	return useable;
}

const bool TGC::Item::isMoveable() const
{
	return moveable;
}

const bool TGC::Item::isDecayning() const
{
	return decaying;
}

const TGC::ENUMS::ItemSlot TGC::Item::getSlotType() const
{
	return slotType;
}

const std::string TGC::Item::getName() const
{
	return name;
}



void TGC::Item::applyPrefabData(ItemPrefab itemPrefab)
{
	this->name = itemPrefab.name;
	this->pickupable = itemPrefab.pickupable;
	this->useable = itemPrefab.useable;
	this->moveable = itemPrefab.moveable;
	this->decaying = itemPrefab.decaying;
	this->decayTo = itemPrefab.decayTo;
	this->attack = itemPrefab.attack;
	this->deffence = itemPrefab.deffence;
	this->slotType = itemPrefab.slotType;
	texture = std::make_shared<sf::Texture>();
	texture = TGC::ResoureManager::getInstance().getTextureHandler().getResourceByName(itemPrefab.texture, "item");

	if (texture)
	{
		if (!animationControler)
		{
			animationControler.emplace(AnimationController());
		}
		animation.setTexture(texture);
		animation.addFrame(sf::IntRect(0, 0, 32, 32));
		animationControler->setAnimation(animation);
	}
	else
	{
		animationControler = std::nullopt;
	}
}

void TGC::Item::draw(sf::RenderWindow& renderWindow)
{
	if (animationControler)
	{
		sprite.setTexture(*animationControler->getTexture());
		sprite.setPosition(position.x*Setting::Const::cellSizeX, position.y * Setting::Const::cellSizeY);
		sprite.setTextureRect(animationControler->getAnimation()->getFrame(animationControler->getCurrentFrame()));
		renderWindow.draw(sprite);

	}
}
