#include "gameCommon.h"

#ifndef WORLD_H
#define WORLD_H

#define WORLD_SIZE_LIMIT 10
#define WORLD_HEIGHT_LIMIT 10

// The blocks are quite basic. Just an id and thats all.
typedef enum Block {
    NONE_BLOCK,
    GRASS_BLOCK
} Block;

typedef struct World {
    Vector3 size; // Might be used later if a allocated world gets added.
    Block blocks[WORLD_HEIGHT_LIMIT][WORLD_SIZE_LIMIT][WORLD_SIZE_LIMIT];
} World;

void drawBlock(Block block, Vector3 position);

void initWorld(World* world);
void drawWorld(World* world, Game* game);

Block getBlockAtWorldPosition(World* world, Vector3 position);

#endif
