#include "cameras.h"

void initMainCamera(Camera3D* camera)
{
    *camera = (Camera3D){
        .position = (Vector3){20.0, 20.0, 20.0},
        .target = (Vector3){0.0, 0.0, 0.0},
        .up = (Vector3){0.0, 1.0, 0.0},
        .fovy = 90,
        .projection = CAMERA_PERSPECTIVE
    };
}

void updateMainCamera(Camera3D* camera)
{
    UpdateCamera(camera, CAMERA_FIRST_PERSON);
}
