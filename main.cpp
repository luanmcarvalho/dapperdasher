#include "raylib.h"

int main ()
{
    SetTargetFPS(60);

    const int width = 1280;
    const int height = 720;

    InitWindow(width, height, "Dapper Dasher");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();

}