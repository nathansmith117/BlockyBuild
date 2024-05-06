#include "gameCommon.h"

#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

typedef struct GameScreen {
    // hehe
} GameScreen;

void initGameScreen(GameScreen* gameScreen);
void updateGameScreen(GameScreen* gameScreen, Game* game);
void closeGameScreen(GameScreen* gameScreen);

#endif
