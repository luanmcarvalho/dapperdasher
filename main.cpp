#include "raylib.h"

int main ()
{
    SetTargetFPS(60);

    // Window Size
    const int windowWidth = 1280;
    const int WindowsHeight = 720;

    // Gravity
    const int gravity = 1;

    InitWindow(windowWidth, WindowsHeight, "Dapper Dasher");

    //rectangle dimensions
    int width = 100;
    int height = 100;

    int  posY = WindowsHeight - height;
    int vel = 0;

    while (!WindowShouldClose())
    {
        //start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (posY >= WindowsHeight - height)
        {
            vel = 0;
        }
        else
        {
            vel += gravity;
        }

          if (IsKeyPressed(KEY_SPACE) && posY >= WindowsHeight - height)
        {
            // Update Velocity
            vel -= 20;
        }

        posY += vel;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        EndDrawing();
    }
    CloseWindow();

}