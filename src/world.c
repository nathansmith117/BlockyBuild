#include "world.h"

void drawBlock(Block block, Vector3 position)
{
    switch (block)
    {
        case NONE_BLOCK:
            break;
        case GRASS_BLOCK:
            DrawCubeV(position, (Vector3){BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}, GREEN);
            DrawCubeWiresV(position, (Vector3){BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}, GRAY);
            break;
        default:
            break;
    }
}

void initWorld(World* world)
{
    for (int y = 0; y < WORLD_HEIGHT_LIMIT; ++y)
    {
        for (int z = 0; z < WORLD_SIZE_LIMIT; ++z)
        {
            for (int x = 0; x < WORLD_SIZE_LIMIT; ++x)
            {
                world->blocks[y][z][x] = GRASS_BLOCK;
            }
        }
    }
}

void drawWorld(World* world, Game* game)
{
    for (int y = 0; y < WORLD_HEIGHT_LIMIT; ++y)
    {
        for (int z = 0; z < WORLD_SIZE_LIMIT; ++z)
        {
            for (int x = 0; x < WORLD_SIZE_LIMIT; ++x)
            {
                // Get position and center the world.
                Vector3 position = (Vector3){x, y, z};
                position.x -= WORLD_SIZE_LIMIT / 2.0;
                position.y -= WORLD_HEIGHT_LIMIT / 2.0;
                position.z -= WORLD_SIZE_LIMIT / 2.0;
                position = Vector3Scale(position, BLOCK_SIZE);

                drawBlock(world->blocks[y][z][x], position);
            }
        }
    }
}
