#include "Arkanoid_BuffSystem.h"


Arkanoid::Buffs::BuffSystem::BuffSystem()
{
}

void Arkanoid::Buffs::BuffSystem::updateBuffs(const double dt)
{
	for (auto it = buffList.begin(); it != buffList.end(); it++)
	{
		(*it)->update(dt);
		if ((*it)->getCurrentDuration() <= 0)
		{
			buffList.erase(it);
			it--;
		}
	}
}

void Arkanoid::Buffs::BuffSystem::updateDrop(const double dt, Arkanoid::GameBoard gameBoard)
{
	for (auto it = buffToCollect.begin(); it != buffToCollect.end(); it++)
	{
		(*it)->update(dt);
		if ((*it)->getPosition().y+(*it)->getBall().getRadius() > gameBoard.getPosition().y + gameBoard.getSize().y)
		{
			buffToCollect.erase(it);
			it--;
		}
	}
}


void Arkanoid::Buffs::BuffSystem::addBuff(std::shared_ptr<Arkanoid::Buffs::IBuff> buff)
{
	if (buff)
	{
		buffList.push_back(buff);
	}
}

void Arkanoid::Buffs::BuffSystem::addBuffToCollect(sf::Vector2f position)
{
	switch ((std::rand() % 3) + 1)
	{
	case 1:
		buffToCollect.push_back(std::move(std::shared_ptr<Arkanoid::Buffs::BuffDropBall>(new BuffDropBall(position, Arkanoid::Buffs::WhatToBuff::PADDLE))));
		break;
	case 2:
		buffToCollect.push_back(std::move(std::shared_ptr<Arkanoid::Buffs::BuffDropBall>(new BuffDropBall(position, Arkanoid::Buffs::WhatToBuff::BALL))));
		break;
	case 3:
		buffToCollect.push_back(std::move(std::shared_ptr<Arkanoid::Buffs::BuffDropBall>(new BuffDropBall(position, Arkanoid::Buffs::WhatToBuff::POINTS))));
		break;
	default:
		break;
	}
}


void Arkanoid::Buffs::BuffSystem::removeAllBuffs()
{
	buffList.clear();
}

std::vector<std::shared_ptr<Arkanoid::Buffs::IBuff>> & Arkanoid::Buffs::BuffSystem::getBufflist()
{
	return this->buffList;
}

std::vector<std::shared_ptr<Arkanoid::Buffs::BuffDropBall>> & Arkanoid::Buffs::BuffSystem::getBuffToCollect()
{
	return this->buffToCollect;
}
