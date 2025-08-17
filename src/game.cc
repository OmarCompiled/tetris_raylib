#include <random>
#include <iostream>

#include "game.h"


Game::Game()
{
	grid = Grid();
	blocks = {IBlock(), JBlock(), LBlock(),TBlock(), SBlock(), OBlock(), ZBlock()};
	currentBlock = RandomBlock();
 	nextBlock = RandomBlock();
	gameover = false;
	score = 0;	
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
	if(gameover && GetKeyPressed()) {
		Reset();
	}

	if(IsKeyPressed(KEY_DOWN)) {
		MoveBlockDown();		
	}

	if(IsKeyPressed(KEY_RIGHT)) {
		MoveBlockRight();
	}

	if(IsKeyPressed(KEY_LEFT)) {
		MoveBlockLeft();
	}

	if(IsKeyPressed(KEY_UP)) {
		RotateBlock();
	}
}

bool
Game::BlockOutOfBounds()
{
	std::vector<Vector2> tiles = currentBlock.GetCells();
	for(auto tile : tiles) {
		if(grid.CellOutOfBounds(tile.x + currentBlock.rowOffset, tile.y + currentBlock.columnOffset)) {
			return true;
		}
	}

	return false;
}

void
Game::MoveBlockDown()
{
	currentBlock.MoveY(1);
	if(BlockOutOfBounds() || !BlockFits()) {
		currentBlock.MoveY(-1);
		LockBlock();
	}
}

void
Game::MoveBlockLeft()
{
	currentBlock.MoveX(-1);
	if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.MoveX(1);
		}
}

void
Game::MoveBlockRight()
{
	currentBlock.MoveX(1);
	if(BlockOutOfBounds() || !BlockFits()) {
		currentBlock.MoveX(-1);
	}
}

void
Game::RotateBlock()
{
	int rotationState = currentBlock.GetRotationState();
	currentBlock.Rotate();
		if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.Rotate(rotationState);
		}
}

void
Game::LockBlock()
{
	std::vector<Vector2> tiles = currentBlock.GetCells();
	for(auto tile : tiles) {
		grid.grid[(int)tile.x + currentBlock.rowOffset][(int)tile.y + currentBlock.columnOffset] = currentBlock.id;
	}

	currentBlock = nextBlock;
	if(!BlockFits()) {
		gameover = true;
	} else {
		nextBlock = RandomBlock();
	}

	grid.ClearRows();
}

bool
Game::BlockFits()
{
	std::vector<Vector2> tiles = currentBlock.GetCells();
	for(auto tile : tiles) {
		if(!grid.CellEmpty(tile.x + currentBlock.rowOffset, tile.y + currentBlock.columnOffset)) {
			return false;
		}
	}

	return true;
}

void
Game::Reset()
{
	grid.Init();
	blocks = {IBlock(), JBlock(), LBlock(),TBlock(), SBlock(), OBlock(), ZBlock()};
	currentBlock = RandomBlock();
 	nextBlock = RandomBlock();
	gameover = false;	
}

void
Game::LetBlockFall()
{
	while(true) {
		if(!BlockOutOfBounds() && BlockFits()) {
			currentBlock.MoveY(1);
		} else {
			currentBlock.MoveY(-1);
			break;
		}
	}	
}
