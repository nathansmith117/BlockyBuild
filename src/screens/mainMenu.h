#include "gameCommon.h"

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

typedef struct MainMenu {
    Rectangle startButton;
} MainMenu;

void initMainMenu(MainMenu* mainMenu);
void updateMainMenu(MainMenu* mainMenu, Game* game);
void resizeMainMenu(MainMenu* mainMenu);
void closeMainMenu(MainMenu* mainMenu);

#endif
