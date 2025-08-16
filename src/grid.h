#ifndef GRID_H
#define GRID_H

#include <vector>
#include <raylib.h>

class Grid 
{
	public:
		Grid();
		void Init();
		void Draw();
		int ClearRows();
		bool CellOutOfBounds(int row, int column);
		bool CellEmpty(int row, int column);
		
		
		int grid[20][10];

	private:
		bool RowComplete(int row);
		void ClearRow(int row);
		void PushRowDown(int row, int numberOfRows);

		int rows;
		int columns;
		int cellSize;
		std::vector<Color> colors;
};

#endif
