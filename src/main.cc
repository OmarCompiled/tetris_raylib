#include <raylib.h>

#include "game.h" /* Has grid.h and blocks.h */


bool
TimePassed(double interval)
{
	static double lastUpdateTime = 0;
	double currentTime = GetTime();

	if(currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}

	return false;
}

int main() {
	InitWindow(650, 900, "Tetris");
	SetTargetFPS(60);
	Game game = Game();

  /* just for testing */

	while (!WindowShouldClose()) {
		game.HandleInput();		
		
		if(TimePassed(0.5)) {
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(BLUE);

		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
