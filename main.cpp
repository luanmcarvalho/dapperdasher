#include "raylib.h"

int main ()
{
    SetTargetFPS(60);

    // Window Size
    const int windowWidth = 1280;
    const int WindowsHeight = 720;

    InitWindow(windowWidth, WindowsHeight, "Dapper Dasher");

    //rectangle dimensions
    int width = 100;
    int height = 100;

    int  posY = WindowsHeight - height;
    int vel = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

          if (IsKeyPressed(KEY_SPACE))
        {
            // Update Velocity
            vel -= 10;
        }

        posY += vel;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        EndDrawing();
    }
    CloseWindow();

}