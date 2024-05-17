#include "gameCommon.h"

#ifndef PLAYER_H
#define PLAYER_H

#define MOUSE_SPEED 0.01
#define PLAYER_SPEED 5.0
#define PLAYER_HEIGHT 2.0

typedef struct Player {
    Camera3D camera;
    
    Vector3 position;
    Vector3 direction;
    Vector3 velocity;
    float speed;

    // Looking around.
    Vector2 cameraAngle;
} Player;

void initPlayer(Player* player);
void updatePlayer(Player* player, Game* game);

#endif
