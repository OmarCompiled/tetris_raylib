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
	InitWindow(650, 720, "Tetris");
	SetTargetFPS(60);

	Game game = Game();

	while (!WindowShouldClose()) {
		game.HandleInput();		
		
		if(TimePassed(0.3)) {
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(GRAY);
		
		DrawTextEx("Score", 410, 10, 38, WHITE);
		DrawRectangleRounded(Rectangle{400, 50, 200, 70}, 0.3, 60, LIGHTGRAY);
		DrawTextEx("Next", 410, 140, 38, WHITE);
		DrawRectangleRounded(Rectangle{400, 180, 180, 180}, 0.3, 60, LIGHTGRAY);
		if(game.gameover) {
			DrawTextEx("Gameover", 410, 400, 38, WHITE);
		}
		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
