#ifndef GAME_H
#define GAME_H

#include <vector>

#include "grid.h"
#include "blocks.h"

class
Game
{
	public:
		Game();
		void Render();
		void HandleInput();

		Grid grid;

	private:
		Block RandomBlock();

		Block currentBlock;
		Block nextBlock;
		std::vector<Block> blocks;
};

#endif
