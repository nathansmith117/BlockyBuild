#include "gameScreen.h"
#include "game.h"
#include "cameras.h"
#include "world.h"

void initGameScreen(GameScreen* gameScreen)
{
}

void updateGameScreen(GameScreen* gameScreen, Game* game)
{
    ClearBackground(BLACK);

    updateMainCamera(&game->mainCamera);

    // Draw 3d world.
    BeginMode3D(game->mainCamera);

    drawWorld(&game->world, game);

    EndMode3D();
}

void closeGameScreen(GameScreen* gameScreen)
{
}
