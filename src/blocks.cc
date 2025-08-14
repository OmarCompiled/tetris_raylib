
#include "blocks.h"

LBlock::LBlock()
{
		id = 1;
		cells[0] = {Vector2{0,2}, Vector2{1,0}, Vector2{1,1}, Vector2{1,2}};
		cells[1] = {Vector2{0,1}, Vector2{1,1}, Vector2{2,1}, Vector2{2,2}};
		cells[2] = {Vector2{1,0}, Vector2{1,1}, Vector2{1,2}, Vector2{2,0}};
		cells[3] = {Vector2{0,0}, Vector2{0,1}, Vector2{1,1}, Vector2{2,1}};
}

JBlock::JBlock()
{
	id = 2;
	cells[0] = {Vector2{0,0},Vector2{1,0},Vector2{1,1},Vector2{1,2}};
	cells[1] = {Vector2{0,1},Vector2{0,2},Vector2{1,1},Vector2{2,1}};
	cells[2] = {Vector2{1,0},Vector2{1,1},Vector2{1,2},Vector2{2,2}};
	cells[3] = {Vector2{0,1},Vector2{1,1},Vector2{2,0},Vector2{2,1}};
}

OBlock::OBlock()
{
	id = 3;
	cells[0] = {Vector2{0,0},Vector2{0,1},Vector2{1,0},Vector2{1,1}};
	
	columnOffset = 4;
}

IBlock::IBlock()
{
	id = 4;
	cells[0] = {Vector2{0,0},Vector2{0,1},Vector2{0,2},Vector2{0,3}};
	cells[1] = {Vector2{1,0},Vector2{1,1},Vector2{1,2},Vector2{1,3}};
}

SBlock::SBlock()
{
	id = 5;
	cells[0] = {Vector2{0,1},Vector2{0,2},Vector2{1,0},Vector2{1,1}};
	cells[1] = {Vector2{0,1},Vector2{1,1},Vector2{1,2},Vector2{2,2}};
	cells[2] = {Vector2{1,1},Vector2{1,2},Vector2{2,0},Vector2{2,1}};
	cells[3] = {Vector2{0,0},Vector2{1,0},Vector2{1,1},Vector2{2,1}};
 };

TBlock::TBlock()
{
	id = 6;
	cells[0] = {Vector2{0,1},Vector2{1,0},Vector2{1,1},Vector2{1,2}};
	cells[1] = {Vector2{0,1},Vector2{1,1},Vector2{1,2},Vector2{2,1}};
	cells[2] = {Vector2{1,0},Vector2{1,1},Vector2{1,2},Vector2{2,1}};
	cells[3] = {Vector2{0,1},Vector2{1,0},Vector2{1,1},Vector2{2,1}};
}

ZBlock::ZBlock()
{
	id = 7;
	cells[0] = {Vector2{0,0},Vector2{0,1},Vector2{1,1},Vector2{1,2}};
	cells[1] = {Vector2{0,2},Vector2{1,1},Vector2{1,2},Vector2{2,1}};
	cells[2] = {Vector2{1,0},Vector2{1,1},Vector2{2,1},Vector2{2,2}};
	cells[3] = {Vector2{0,1},Vector2{1,0},Vector2{1,1},Vector2{2,0}};
}
