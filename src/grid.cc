#include <raylib.h>

#include "grid.h"

Grid::Grid() {
  rows = 20;
  columns = 10;
  cellSize = 35;
  Init();
  colors = {
      Color{30, 30, 54, 255},  Color{114, 203, 59, 255},
      Color{255, 50, 19, 255}, Color{255, 151, 28, 255},
      Color{255, 213, 0, 255}, Color{3, 65, 174, 255}
  };
}

void
Grid::Init() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      grid[i][j] = 0;
    }
  }
}

void
Grid::Draw() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int cellValue = grid[i][j];
      DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

bool
Grid::CellOutOfBounds(int row, int column)
{
	if(row >= 0 && row < rows && column >= 0 && column < columns) {
		return false;
	}

	return true;
}

bool
Grid::CellTouchedFloor(int row)
{
	if(row >= rows) {
		return true;
	}

	return false;
}
