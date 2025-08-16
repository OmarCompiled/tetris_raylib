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
		void MoveBlockDown();
		void MoveBlockRight();
		void MoveBlockLeft();
		void RotateBlock();

		Grid grid;

	private:
		Block RandomBlock();
		bool BlockOutOfBounds();
		bool BlockTouchedFloor(std::vector<Vector2> tiles);

		Block currentBlock;
		Block nextBlock;
		std::vector<Block> blocks;
};

#endif
