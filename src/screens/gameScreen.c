#include "gameScreen.h"
#include "game.h"
#include "world.h"
#include "player.h"

void initGameScreen(GameScreen* gameScreen)
{
}

void updateGameScreen(GameScreen* gameScreen, Game* game)
{
    ClearBackground(BLACK);

    updatePlayer(&game->player, game);

    // draw 3d shit.
    BeginMode3D(game->player.camera);

    drawWorld(&game->world, game);

    EndMode3D();
}

void closeGameScreen(GameScreen* gameScreen)
{
}
