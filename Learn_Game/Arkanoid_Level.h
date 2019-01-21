#pragma once
#include "Arkanoid_Block.h"
#include <vector>
#include <memory>
#include <utility>
namespace Arkanoid
{
	class Level
	{
		std::vector<std::shared_ptr<Arkanoid::Block>> blockList;
	protected:
		void addBlock(std::shared_ptr<Arkanoid::Block> block);
	public:
		Level();
		~Level() = default;
		std::shared_ptr<Arkanoid::Level> getNextLevel();
		std::vector<std::shared_ptr<Arkanoid::Block>> getBlockList();
	};
}

