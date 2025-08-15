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
		bool CellOutOfBounds(int row, int column);
		bool CellTouchedFloor(int row);

		int grid[20][10];

	private:
		int rows;
		int columns;
		int cellSize;
		std::vector<Color> colors;
};

#endif
