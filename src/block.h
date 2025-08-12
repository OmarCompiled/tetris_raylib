#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <raylib.h>
#include <vector>

class Block {
public:
  Block();

  std::map<int, std::vector<Vector2>> cells;
  int id;

private:
  int cellSize;
  int rotationState;
};

#endif
