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

		int grid[20][10];

	private:
		int rows;
		int cols;
		int cellSize;
		std::vector<Color> colors;
};

#endif
