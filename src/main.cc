#include <raylib.h>

#include "game.h" /* Has grid.h and blocks.h */

int main() {
	InitWindow(650, 900, "Tetris");
	SetTargetFPS(60);
	Game game = Game();

  /* just for testing */

	while (!WindowShouldClose()) {
		game.HandleInput();		

		BeginDrawing();
		ClearBackground(BLUE);

		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
