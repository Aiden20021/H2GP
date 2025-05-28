#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib - Simple Window Example");

    SetTargetFPS(60); // Set the game to run at 60 frames per second

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update (if needed)

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE); // Clear the screen with a white background

        DrawText("Welcome to raylib!", 190, 200, 20, LIGHTGRAY); // Display some text

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close the window and clean up resources

    return 0;
}