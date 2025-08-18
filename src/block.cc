#include "block.h"

Block::Block()
{
	cellSize = 35;
	rotationState = 0;
	rowOffset = 0;
	columnOffset = 3;
	colors = {
      Color{30, 30, 54, 255},  Color{114, 203, 59, 255},
      Color{255, 50, 19, 255}, Color{255, 151, 28, 255},
      Color{255, 213, 0, 255}, SKYBLUE, PURPLE,
			Color{3, 65, 174, 255},
  };
}

void
Block::Draw(int offsetX, int offsetY)
{
	std::vector<Vector2> tiles = cells.at(rotationState);
	for(Vector2 v : tiles) {
		DrawRectangle((v.y + columnOffset) * cellSize + offsetX, (v.x + rowOffset) * cellSize + offsetY, cellSize - 1, cellSize - 1, colors.at(id));
	}
}

void
Block::MoveX(int t)
{
	columnOffset += 1 * t;
}

void
Block::MoveY(int t)
{
	rowOffset += 1 * t;
}

void
Block::Rotate(int t)
{
	if(t < 0) {
		rotationState == cells.size() - 1 ?	rotationState = 0 : rotationState++;
	} else {
		rotationState = t;
	}
}

std::vector<Vector2>
Block::GetCells()
{
	return cells.at(rotationState);
}

int
Block::GetRotationState()
{
	return rotationState;
}
