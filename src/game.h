#include "gameCommon.h"
#include "screensInclude.h"
#include "world.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

typedef enum ScreenID {
    MAIN_MENU_SCREEN,
    GAME_SCREEN
} ScreenID;

typedef struct Game {
    ScreenID screenID;
    MainMenu mainMenu;
    GameScreen gameScreen;

    World world;
    Player player;
} Game;

void initGame(Game* game);
void updateGame(Game* game);
void closeGame(Game* game);

#endif
