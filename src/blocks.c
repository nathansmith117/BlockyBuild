#include "blocks.h"

Blocks createBlocks(int width, int height)
{
    Blocks blocks;
    blocks.width = width;
    blocks.height = height;

    blocks.map = (BlockType*)BB_CALLOC(width * height, sizeof(BlockType));

    if (blocks.map == NULL)
    {
        ALLOCATION_ERROR;
    }

    return blocks;
}

void freeBlocks(Blocks blocks)
{
    if (blocks.map != NULL)
    {
        BB_FREE(blocks.map);
    }
}
