#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <raylib.h>
#include <vector>

class Block {
	public:
  	Block();
		void Draw();
		void MoveX(int t = 1);
		void MoveY(int t = 1);
		void Rotate();
		std::vector<Vector2> GetCells();

  	std::map<int, std::vector<Vector2>> cells;
  	int id;
		int rowOffset;
		int columnOffset;

	private:
  	int cellSize;
  	int rotationState;
		std::vector<Color> colors;
};

#endif
