#include "game.h"

void initGame(Game* game)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Blocky Build");

    // Screens.
    game->screenID = MAIN_MENU_SCREEN;
    initMainMenu(&game->mainMenu);
    initGameScreen(&game->gameScreen);
}

void updateGame(Game* game)
{
    BeginDrawing();

    switch (game->screenID)
    {
        case MAIN_MENU_SCREEN:
            updateMainMenu(&game->mainMenu, game);
            break;
        case GAME_SCREEN:
            updateGameScreen(&game->gameScreen, game);
            break;
        default:
            break;
    }

    EndDrawing();
}

void closeGame(Game* game)
{
    closeMainMenu(&game->mainMenu);
    closeGameScreen(&game->gameScreen);
    
    CloseWindow();
}
