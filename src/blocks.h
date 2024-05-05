#include "gameCommon.h"

#ifndef BLOCKS_H
#define BLOCKS_H

typedef enum BlockType {
    GRASS
} BlockType;

// Holds all the blocks in the world.
typedef struct Blocks {
    int width;
    int height;
    BlockType* map;
} Blocks;

Blocks createBlocks(int width, int height);
void freeBlocks(Blocks blocks);

#endif
