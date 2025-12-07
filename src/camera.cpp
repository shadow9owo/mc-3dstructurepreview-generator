#include "camera.hpp"
#include <raymath.h>

FreeCamera::FreeCamera()
{
    cam.position = { 0.0f, 0.0f, 0.0f };
    cam.target   = { 0.0f, 0.0f, 1.0f };
    cam.up       = { 0.0f, 1.0f, 0.0f };
    cam.fovy     = 70.0f;
    cam.projection = CAMERA_PERSPECTIVE;
}

void FreeCamera::Update(float dt)
{
    Vector2 delta = GetMouseDelta();
    yaw -= delta.x * sensitivity * dt * 60.0f;
    pitch -= delta.y * sensitivity * dt * 60.0f;

    if (pitch > 89.0f)  pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    Vector3 forward = {
        cosf(DEG2RAD * pitch) * sinf(DEG2RAD * yaw),
        sinf(DEG2RAD * pitch),
        cosf(DEG2RAD * pitch) * cosf(DEG2RAD * yaw)
    };

    Vector3 right = {
        sinf(DEG2RAD * (yaw + 90.0f)),
        0.0f,
        cosf(DEG2RAD * (yaw + 90.0f))
    };

    if (IsKeyDown(KEY_W)) cam.position = Vector3Add(cam.position, Vector3Scale(forward,speed * dt));
    if (IsKeyDown(KEY_S)) cam.position = Vector3Add(cam.position, Vector3Scale(forward,-speed * dt));
    if (IsKeyDown(KEY_D)) cam.position = Vector3Add(cam.position, Vector3Scale(right,-speed * dt));
    if (IsKeyDown(KEY_A)) cam.position = Vector3Add(cam.position, Vector3Scale(right,speed * dt));

    cam.target = Vector3Add(cam.position, forward);
}
