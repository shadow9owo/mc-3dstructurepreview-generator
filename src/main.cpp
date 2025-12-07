#include "raylib.h"
#include "camera.hpp"
#include "rlImGui.h"

#include "imgui.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(1280, 720, "preview");

	FreeCamera fc;
	
	DisableCursor();

	SetTargetFPS(60);

	bool open = true;

	rlImGuiSetup(true);

	SetExitKey(0);

	fc.cam.position = {0,30};

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(WHITE);

		rlImGuiBegin();

		if (!open)
		{
			fc.Update(GetFrameTime());

			BeginMode3D(fc.cam);

        	    DrawGrid(1024, 1.0f);

			EndMode3D();
		}else 
		{
			ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);

			if (ImGui::Begin("Config",&open,ImGuiWindowFlags_NoResize))
			{
				
			}
			ImGui::End();
		}

		if (IsKeyPressed(KEY_ESCAPE)) {open = !open;}

		rlImGuiEnd();

		EndDrawing();
	}

 	rlImGuiShutdown();
	CloseWindow();
	return 0;
}
