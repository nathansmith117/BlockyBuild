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
    world->size = (Vector3){WORLD_SIZE_LIMIT, WORLD_HEIGHT_LIMIT, WORLD_SIZE_LIMIT};

    for (int y = 0; y < world->size.y; ++y)
    {
        for (int z = 0; z < world->size.z; ++z)
        {
            for (int x = 0; x < world->size.x; ++x)
            {
                world->blocks[y][z][x] = GRASS_BLOCK;
            }
        }
    }
}

void drawWorld(World* world, Game* game)
{
    for (int y = 0; y < world->size.y; ++y)
    {
        for (int z = 0; z < world->size.z; ++z)
        {
            for (int x = 0; x < world->size.x; ++x)
            {
                // Get position and center the world.
                Vector3 position = (Vector3){x, y, z};
                position.x -= world->size.x / 2.0;
                position.y -= world->size.y / 2.0;
                position.z -= world->size.z / 2.0;

                drawBlock(world->blocks[y][z][x], position);
            }
        }
    }
}

Block getBlockAtWorldPosition(World* world, Vector3 position)
{
    Vector3 blockPosition = Vector3Subtract(position, Vector3Scale(world->size, 0.0));
    blockPosition = (Vector3){(int)blockPosition.x, (int)blockPosition.y, (int)blockPosition.z};

    // Check bounds
    if (blockPosition.x < 0.0 || blockPosition.x >= world->size.x ||
        blockPosition.y < 0.0 || blockPosition.y >= world->size.y ||
        blockPosition.z < 0.0 || blockPosition.z >= world->size.z)
    {
        return NONE_BLOCK;
    }
    
    return world->blocks[(int)blockPosition.y][(int)blockPosition.z][(int)blockPosition.x];
}
