#include "raylib.h"

struct animData
{
    int frame;
    int updateTime;
    int runningTime;
    Vector2 position;
    Rectangle rec;
};


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
    const int gravity = 1000;

    // Velocity
    int vel = 0;

    // scarfy animation frame
    int scarfyFrame = 0;

    // nebula animation frame
    int nebulaFrame = 0;

    // Update Time
    const float updateTime = 1.0/12.0;

    // Running Time
    float runningTime = 0;

    // Nebula setup
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle Recnebula;
    Vector2 nebulaPosition;

    // Set the dimensions of the rectangle
    Recnebula.height = nebula.height/8;
    Recnebula.width = nebula.width/8;
    Recnebula.x = 0;
    Recnebula.y = 0;

    // Nebula Initial position
    nebulaPosition.y = WindowsHeight - Recnebula.height;
    nebulaPosition.x = windowWidth;

    //nebula velocity
    int nebulaVel = -300;


    while (!WindowShouldClose())
    {
        //start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Delta Time
        const float dT = GetFrameTime();

        // Ground check
        if (scarfyPosition.y >= WindowsHeight - Recscarfy.height)
        {
            vel = 0;
        }
        else{
                scarfyFrame = 0;
                vel += gravity * dT * 1.5;
            }


        // Jump
          if (IsKeyPressed(KEY_SPACE) && scarfyPosition.y >= WindowsHeight - Recscarfy.height)
        {
            // Update Velocity
            vel -= 1000;
        }

         // Nebula Movement
        nebulaPosition.x += nebulaVel * dT;

        //scarfy Movement
        scarfyPosition.y += vel * dT;

        runningTime += dT;


        if (runningTime >= updateTime)
        {
            runningTime = 0.0;
            Recscarfy.x = scarfyFrame * Recscarfy.width;
            scarfyFrame++;

            if (scarfyFrame > 5)
            {
                scarfyFrame = 0;
            }

            Recnebula.x = nebulaFrame * Recnebula.width;
            nebulaFrame++;

            if (nebulaFrame > 7)
            {
                nebulaFrame = 0;
                Recnebula.y += Recnebula.height;
            }

            if (Recnebula.y >= nebula.height)
            {
                Recnebula.y = 0;
            }

        }


        DrawTextureRec(scarfy, Recscarfy, scarfyPosition, WHITE);
        DrawTextureRec(nebula, Recnebula, nebulaPosition, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();

}