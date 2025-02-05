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
    animData nebulaData;

    // Nebula rectangle dimensions and position
    nebulaData.rec.height = nebula.height/8;
    nebulaData.rec.width = nebula.width/8;
    nebulaData.rec.x = 0;
    nebulaData.rec.y = 0;

    // Nebula position
    nebulaData.position.y = WindowsHeight - nebulaData.rec.height;
    nebulaData.position.x = windowWidth;

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
        else{
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
        nebulaData.position.x += nebulaVel * dT;

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

            nebulaData.rec.x = nebulaData.frame * nebulaData.rec.width;
            nebulaData.frame++;

            if (nebulaData.frame > 7)
            {
                nebulaData.frame = 0;
                nebulaData.rec.y += nebulaData.rec.height;
            }

            if (nebulaData.rec.y >= nebula.height)
            {
                nebulaData.rec.y = 0;
            }

        }   // End of Loop------------------------------------------------

        // Draw
        DrawTextureRec(nebula, nebulaData.rec, nebulaData.position, WHITE);
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.position, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();

}