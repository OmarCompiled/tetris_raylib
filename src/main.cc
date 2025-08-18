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
	
	Font retrobyte = LoadFontEx("./RetroByte.ttf", 64, NULL, 0);

	Game game = Game();
	std::string score;

	while (!WindowShouldClose()) {
		score = std::to_string(game.score);
		Vector2 scoreTextSize = MeasureTextEx(retrobyte, score.c_str(), 38, 2);

		game.HandleInput();
		
		if(TimePassed(0.4)) {
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(GRAY);
		
		DrawTextEx(retrobyte, "Score", Vector2{410, 10}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 50, 200, 70}, 0.3, 60, Color{32,32,32,255});
		DrawTextEx(retrobyte, score.c_str(), Vector2{400 + (200 - scoreTextSize.x) / 2, 50 + (70 - scoreTextSize.y) / 2}, 38, 2, WHITE); /* Centering Score inside rectangle*/
		DrawTextEx(retrobyte, "Next", Vector2{410, 140}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{400, 180, 180, 180}, 0.3, 60, Color{32,32,32,255});

		if(game.gameover) {
			DrawTextEx(retrobyte, "Gameover", Vector2{410, 400}, 38, 2, WHITE);
		}

		game.Render();

		EndDrawing();
  }

	CloseWindow();
}
