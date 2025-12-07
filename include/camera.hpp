#pragma once
#include "raylib.h"
#include <cmath>

class FreeCamera
{
public:
    Camera3D cam = { 0 };

    float yaw = 0.0f;
    float pitch = 0.0f;
    float speed = 10.0f;
    float sensitivity = 0.12f;

    FreeCamera();

    void Update(float dt);
};
