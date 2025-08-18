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
												/* NOTE: since I Draw blocks relative to the grid, I'll have to either
													hard code the offsets or change the whole draw function. Choosing the easier path :) */ 
												/* Nevermind, I'll just make a new function :) */
	if(nextBlock.id == 4) {
		nextBlock.DrawPreview(420, 200);
	} else if(nextBlock.id == 6){
		nextBlock.DrawPreview(437, 217);
	} else {
		nextBlock.DrawPreview(455, 235);
	}
}

void
Game::HandleInput()
{
	if(gameover && GetKeyPressed()) {
		Reset();
	}
	
	if(IsKeyPressed(KEY_SPACE)) {
		LetBlockFall();
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
	if(!gameover) {
		currentBlock.MoveY(1);
		if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.MoveY(-1);
			LockBlock();
			score++;
		}
	}
}

void
Game::MoveBlockLeft()
{
	if(!gameover) {
		currentBlock.MoveX(-1);
		if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.MoveX(1);
		}
	}
}

void
Game::MoveBlockRight()
{
	if(!gameover) {
		currentBlock.MoveX(1);
		if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.MoveX(-1);
		}
	}
}

void
Game::RotateBlock()
{
	if(!gameover) {
		int rotationState = currentBlock.GetRotationState();
		currentBlock.Rotate();
		if(BlockOutOfBounds() || !BlockFits()) {
			currentBlock.Rotate(rotationState);
		}
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
		return;
	} else {
		nextBlock = RandomBlock();
	}
	
	switch(grid.ClearRows()) {
		case 1: 
			score += 100;
			break;
		case 2:
			score += 300;
			break;
		case 3:
			score += 500;
	}
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
	score = 0;
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
