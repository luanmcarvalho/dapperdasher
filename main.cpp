#include "raylib.h"

int main ()
{
    SetTargetFPS(60);

      // Window Size
    const int windowWidth = 1280;
    const int WindowsHeight = 720;

    InitWindow(windowWidth, WindowsHeight, "Dapper Dasher");

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle Recscarfy;

    // Set the dimensions of the rectangle
    Recscarfy.height = scarfy.height;
    Recscarfy.width = scarfy.width/6;
    Recscarfy.x = 0;
    Recscarfy.y = 0;

    // Scarfy position
    Vector2 scarfyPosition;
    scarfyPosition.x = windowWidth/2 - Recscarfy.width/2;
    scarfyPosition.y = WindowsHeight - Recscarfy.height;

    // Gravity
    const int gravity = 1;

    // Velocity
    int vel = 0;

    while (!WindowShouldClose())
    {
        //start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Ground check
        if (scarfyPosition.y >= WindowsHeight - Recscarfy.height)
        {
            vel = 0;
        }
        else
        {
            vel += gravity;
        }

        // Jump
          if (IsKeyPressed(KEY_SPACE) && scarfyPosition.y >= WindowsHeight - Recscarfy.height)
        {
            // Update Velocity
            vel -= 20;
        }

        scarfyPosition.y += vel;

        DrawTextureRec(scarfy, Recscarfy, scarfyPosition, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();

}