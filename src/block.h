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

  	std::map<int, std::vector<Vector2>> cells;
  	int id;

	private:
  	int cellSize;
  	int rotationState;
		std::vector<Color> colors;

	protected:
		int rowOffset;
		int columnOffset;
};

#endif
