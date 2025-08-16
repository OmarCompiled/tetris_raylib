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
      Color{255, 213, 0, 255}, SKYBLUE, PURPLE,
			Color{3, 65, 174, 255}
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
                    cellSize - 1, colors.at(cellValue));
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
Grid::CellEmpty(int row, int column)
{
	if(!grid[row][column]) {
		return true;
	}

	return false;
}

bool
Grid::RowComplete(int row)
{
	for(int column = 0; column < columns; column++) {
		if(!grid[row][column]) {
			return false;
		}
	}	

	return true;
}

void
Grid::ClearRow(int row)
{
	for(int column = 0; column < columns; column++) {
		grid[row][column] = 0;
	}
}

void
Grid::PushRowDown(int row, int numberOfRows)
{
	for(int column = 0; column < columns; column++) {
		grid[row + numberOfRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}

int
Grid::ClearRows()
{
	int completedRows = 0;
	for(int row = rows - 1; row >=0; row--) {
		if(RowComplete(row)) {
			ClearRow(row);
			completedRows++;
		} else if(completedRows > 0){
			PushRowDown(row, completedRows);
		}
	}

	return completedRows;
}
