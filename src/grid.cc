#include <raylib.h>

#include "grid.h"

Grid::Grid()
{
	rows = 20;
	cols = 10;
	cellSize = 35;
	Init();
	colors = 
	{
		Color {30,30,54,255},
		Color {114,203,59,255},
		Color {255,50,19,255},
		Color {255,151,28,255},
		Color {255,213,0,255},
		PURPLE,
		SKYBLUE,
		Color {3,65,174,255}
	};
}

void
Grid::Init()
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			grid[i][j] = 0;
		}
	}
}

void
Grid::Draw()
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			int cellValue = grid[i][j];
			DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}
