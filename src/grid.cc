#include <raylib.h>

#include "colors.h"
#include "grid.h"

Grid::Grid() {
  rows = 20;
  cols = 10;
  cellSize = 35;
  Init();
  colors = {
		Gray,
		Green,
		Red,
		Orange,
		Yellow,
		PURPLE,
		SKYBLUE,
		Blue
	};
}

void Grid::Init() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = 0;
    }
  }
}

void Grid::Draw() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int cellValue = grid[i][j];
      DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}
