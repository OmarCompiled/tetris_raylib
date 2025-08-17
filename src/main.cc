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
	
	Font monospace = LoadFontEx("./RetroByte.ttf", 64, NULL, 0);

	Game game = Game();

	while (!WindowShouldClose()) {
		game.HandleInput();

		if(IsKeyPressed(KEY_SPACE)) {
			game.LetBlockFall();
		}	
		
		if(TimePassed(0.4)) {
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(GRAY);
		
		DrawTextEx(monospace, "Score", Vector2{410, 10}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 50, 200, 70}, 0.3, 60, LIGHTGRAY);
		DrawTextEx(monospace, "Next", Vector2{410, 140}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 180, 180, 180}, 0.3, 60, LIGHTGRAY);
		if(game.gameover) {
			DrawTextEx(monospace, "Gameover", Vector2{410, 400}, 38, 2, WHITE);
		}
		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
