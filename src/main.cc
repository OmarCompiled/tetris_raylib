#include <raylib.h>
#include <string>

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
		std::string score = std::to_string(game.score);

		game.HandleInput();
		
		if(TimePassed(0.4)) {
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(GRAY);
		
		DrawTextEx(monospace, "Score", Vector2{410, 10}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 50, 200, 70}, 0.3, 60, Color{32,32,32,255});
		DrawTextEx(monospace, score.c_str(), Vector2{410, 60}, 38, 2, WHITE);
		DrawTextEx(monospace, "Next", Vector2{410, 140}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 180, 180, 180}, 0.3, 60, Color{32,32,32,255});

		if(game.gameover) {
			DrawTextEx(monospace, "Gameover", Vector2{410, 400}, 38, 2, WHITE);
		}

		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
