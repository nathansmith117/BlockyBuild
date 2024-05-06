#include "world.h"

void drawBlock(Block block, Vector3 position)
{
    switch (block)
    {
        case NONE_BLOCK:
            break;
        case GRASS_BLOCK:
            DrawCubeV(position, (Vector3){1.0, 1.0, 1.0}, GREEN);
            DrawCubeWiresV(position, (Vector3){1.0, 1.0, 1.0}, GRAY);
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

                drawBlock(world->blocks[y][z][x], position);
            }
        }
    }
}
