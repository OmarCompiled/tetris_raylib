#include <random>

#include "game.h"


Game::Game()
{
	grid = Grid();
	blocks = {IBlock(), JBlock(), LBlock(),TBlock(), SBlock(), OBlock(), ZBlock()};
	currentBlock = RandomBlock();
 	nextBlock = RandomBlock();	
}

Block
Game::RandomBlock()
{
	if(blocks.empty()) {
		blocks = {IBlock(), JBlock(), LBlock(),TBlock(), SBlock(), OBlock(), ZBlock()};
	}

	int randIndex = rand() % blocks.size();
	Block randBlock = blocks[randIndex];
	blocks.erase(blocks.begin() + randIndex);

	return randBlock;
}

void
Game::Render()
{
	grid.Draw();
	currentBlock.Draw();
}

void
Game::HandleInput()
{
	if(IsKeyPressed(KEY_DOWN)) {
		currentBlock.MoveY();
	}

	if(IsKeyPressed(KEY_RIGHT)) {
		currentBlock.MoveX(1);
	}

	if(IsKeyPressed(KEY_LEFT)) {
		currentBlock.MoveX(-1);
	}

	if(IsKeyPressed(KEY_UP)) {
		currentBlock.Rotate();
	}
}
