#include "raylib.h"

struct animData
{
    int frame;
    float updateTime;
    float runningTime;
    Vector2 position;
    Rectangle rec;
};


int main ()
{
    // Initialize the window
    SetTargetFPS(60);
    const int windowWidth = 1280;
    const int WindowsHeight = 720;
    InitWindow(windowWidth, WindowsHeight, "Dapper Dasher");

    // -------------------------------------------------------------
    // Scarfy setup
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    animData scarfyData;

    // Scarfy rectangle dimensions and position
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;

    // Scarfy position
    scarfyData.position.y = WindowsHeight - scarfyData.rec.height;
    scarfyData.position.x = windowWidth/2 - scarfyData.rec.width/2;

    // Scarfy animation setup
    scarfyData.frame = 0;
    scarfyData.updateTime = 1.0/12.0;
    scarfyData.runningTime = 0;
    // -------------------------------------------------------------

    // -------------------------------------------------------------
    // Game Physics
    // Gravity
    const int gravity = 1000;

    // Velocity
    int vel = 0;
    // -------------------------------------------------------------

    // -------------------------------------------------------------
    // Nebula setup
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

    const int nebulaNum {10};
    animData nebulaE[nebulaNum]{};

    for (int i = 0; i < nebulaNum; i++)
    {
        nebulaE[i].frame = 0;
        nebulaE[i].updateTime = 1.0/16.0;
        nebulaE[i].runningTime = 0;
        nebulaE[i].rec.height = nebula.height/8;
        nebulaE[i].rec.width = nebula.width/8;
        nebulaE[i].rec.x = 0;
        nebulaE[i].rec.y = 0;
        nebulaE[i].position.y = WindowsHeight - nebulaE[i].rec.height;
        nebulaE[i].position.x = windowWidth + i * 500;
    }


    //nebula movement
    int nebulaVel = -300;
    //--------------------------------------------------------------

    // Game Loop----------------------------------------------------
    while (!WindowShouldClose())
    {
        //start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Delta Time
        const float dT = GetFrameTime();

        // Ground check
        if (scarfyData.position.y >= WindowsHeight - scarfyData.rec.height)
        {
            vel = 0;
        }
        else
        {
            scarfyData.frame = 0;
            vel += gravity * dT * 1.5;
        }


        // Jump
          if (IsKeyPressed(KEY_SPACE) && scarfyData.position.y >= WindowsHeight - scarfyData.rec.height)
        {
            // Update Velocity
            vel -= 1000;
        }

         // Nebula Movement
        for (int i = 0; i < nebulaNum; i++)
        {
            nebulaE[i].position.x += nebulaVel * dT;
        }

        //scarfy Movement
        scarfyData.position.y += vel * dT;

        scarfyData.runningTime += dT;


        if (scarfyData.runningTime >= scarfyData.updateTime)
        {
            scarfyData.runningTime = 0.0;
            scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
            scarfyData.frame++;

            if (scarfyData.frame > 5)
            {
                scarfyData.frame = 0;
            }
        }
        // Nebula update
        for (int i = 0; i < nebulaNum; i++)
        {
            nebulaE[i].runningTime += dT;
            if (nebulaE[i].runningTime >= nebulaE[i].updateTime)
            {
                nebulaE[i].runningTime = 0.0;
                nebulaE[i].rec.x = nebulaE[i].frame * nebulaE[i].rec.width;
                nebulaE[i].frame++;

                if (nebulaE[i].frame > 7)
                {
                    nebulaE[i].frame = 0;
                    nebulaE[i].rec.y += nebulaE[i].rec.height;
                }

                if (nebulaE[i].rec.y >= nebula.height)
                {
                    nebulaE[i].rec.y = 0;
                }
            }
        }
        // End of Loop------------------------------------------------

        // Draw
        for (int i = 0; i < nebulaNum; i++)
        {
            DrawTextureRec(nebula, nebulaE[i].rec, nebulaE[i].position, WHITE);
        }
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.position, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();

}