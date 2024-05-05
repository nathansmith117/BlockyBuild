#include "game.h"

void initGame(Game* game)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Blocky Build");
}

void updateGame(Game* game)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(5, 5);

    EndDrawing();
}

void closeGame(Game* game)
{
    CloseWindow();
}
