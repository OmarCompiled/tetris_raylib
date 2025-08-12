#include <raylib.h>

#include "grid.h"

int
main()
{
	InitWindow(600, 900, "Tetris");

	/*int display = GetCurrentMonitor();
	int Vw = GetMonitorWidth(display);
	int Vh = GetMonitorHeight(display);

	SetWindowSize(Vw, Vh);
	ToggleFullscreen();*/
	
	Grid grid = Grid();
	grid.Init();
	grid.grid[0][0] = 1;
	grid.grid[0][1] = 1;

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(DARKBLUE);		

		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
}
