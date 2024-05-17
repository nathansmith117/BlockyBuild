#include "player.h"
#include "game.h"
#include "world.h"

void initPlayer(Player* player)
{
    // Create camera.
    player->camera = (Camera3D){
        .up = (Vector3){0.0, 1.0, 0.0},
        .fovy = 90.0,
        .projection = CAMERA_PERSPECTIVE
    };

    player->position = (Vector3){0.0, WORLD_HEIGHT_LIMIT / 2.0 + 0.0, 0.0};
    player->direction = (Vector3){0.0, 0.0, 1.0};
    player->velocity = Vector3Zero();
    player->speed = PLAYER_SPEED;

    player->cameraAngle = Vector2Zero();
}

void updatePlayerControls(Player* player, Game* game)
{
    Vector2 mouseDelta = Vector2Scale(GetMouseDelta(), MOUSE_SPEED);

    // Update camera angle.
    player->cameraAngle = Vector2Add(player->cameraAngle, mouseDelta);
    player->cameraAngle.x = Wrap(player->cameraAngle.x, -PI, PI);
    player->cameraAngle.y = Clamp(player->cameraAngle.y, -PI / 2.5, PI / 2.5);

    // Set direction.
    Matrix matrix = MatrixRotateXYZ((Vector3){-player->cameraAngle.y, player->cameraAngle.x, 0.0});
    player->direction = (Vector3){matrix.m2, matrix.m6, matrix.m10};

    // Update velocity.
    player->velocity = Vector3Zero();

    if (IsKeyDown(KEY_W))
    {
        player->velocity.z += cos(player->cameraAngle.x);
        player->velocity.x += -sin(player->cameraAngle.x);
    }
    if (IsKeyDown(KEY_A))
    {
        player->velocity.z += cos(player->cameraAngle.x - (PI / 2.0));
        player->velocity.x += -sin(player->cameraAngle.x - (PI / 2.0));
    }
    if (IsKeyDown(KEY_S))
    {
        player->velocity.z += -cos(player->cameraAngle.x);
        player->velocity.x += sin(player->cameraAngle.x);
    }
    if (IsKeyDown(KEY_D))
    {
        player->velocity.z += cos(player->cameraAngle.x + (PI / 2.0));
        player->velocity.x += -sin(player->cameraAngle.x + (PI / 2.0));
    }

    player->velocity = Vector3Scale(player->velocity, PLAYER_SPEED);
}

void handleCollisionWithWorldPlayer(Player* player, Game* game)
{
    World* world = &game->world;

    // Player bounding box.
    float playerSize = 0.2;
    
    BoundingBox playerBox = (BoundingBox){
        .min = (Vector3){-playerSize, -PLAYER_HEIGHT / 2.0, -playerSize},
        .max = (Vector3){playerSize, 0.0, playerSize}
    };

    playerBox.min = Vector3Add(playerBox.min, player->position);
    playerBox.max = Vector3Add(playerBox.max, player->position);

    // Check bear by blocks.
    int checkCollisionDistance = 2.0;

    DrawBoundingBox(playerBox, BLUE);

    for (int y = -checkCollisionDistance; y < checkCollisionDistance; ++y)
    {
        for (int z = -checkCollisionDistance; z < checkCollisionDistance; ++z)
        {
            for (int x = -checkCollisionDistance; x < checkCollisionDistance; ++x)
            {
                int currentX = player->position.x + x;
                int currentY = player->position.y + y;
                int currentZ = player->position.z + z;

                Vector3 blockPosition = (Vector3){currentX, currentY, currentZ};
                Block block = getBlockAtWorldPosition(world, blockPosition);

                // No block here.
                if (block == NONE_BLOCK)
                {
                    continue;
                }

                // Check collision.
                BoundingBox blockBox = (BoundingBox){
                    .min = (Vector3){-0.5, -0.5, -0.5},
                    .max = (Vector3){0.5, 0.5, 0.5}
                };

                blockBox.min = Vector3Add(blockBox.min, blockPosition);
                blockBox.max = Vector3Add(blockBox.max, blockPosition);

                DrawBoundingBox(blockBox, RED);

                // If collided.
                if (CheckCollisionBoxes(playerBox, blockBox))
                {
                    puts("hi");
                }
            }
        }
    }
}

void updatePlayer(Player* player, Game* game)
{
    updatePlayerControls(player, game);
    handleCollisionWithWorldPlayer(player, game);

    // Apply velocity.
    player->position = Vector3Add(
        player->position,
        Vector3Scale(player->velocity, GetFrameTime())
    );

    // Update camera.
    player->camera.position = player->position;
    player->camera.target = Vector3Add(player->position, player->direction);
}
