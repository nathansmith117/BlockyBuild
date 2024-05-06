#include "mainMenu.h"
#include "game.h"

void initMainMenu(MainMenu* mainMenu)
{
    resizeMainMenu(mainMenu);
}

void updateMainMenu(MainMenu* mainMenu, Game* game)
{
    ClearBackground(RAYWHITE);

    // Start button.
    if (GuiButton(mainMenu->startButton, "Start"))
    {
        game->screenID = GAME_SCREEN;
    }

    // Handle resize.
    if (IsWindowResized())
    {
        resizeMainMenu(mainMenu);
    }
}

void resizeMainMenu(MainMenu* mainMenu)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    int buttonWidth = 150;
    int buttonHeight = 80;

    // Start button.
    mainMenu->startButton.x = width / 2.0 - buttonWidth / 2.0;
    mainMenu->startButton.y = height / 2.0 - buttonHeight / 2.0;
    mainMenu->startButton.width = buttonWidth;
    mainMenu->startButton.height = buttonHeight;
}

void closeMainMenu(MainMenu* mainMenu)
{
}
