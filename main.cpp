
//#include "ceserial.h"
#include "raylib.h"
#include <string>
#include <sstream>

using namespace std;

struct DashboardPanel {
    Rectangle bounds;
    const char *title;
    Color backgroundColor;
};

int main(void)
{
    // Init raylib window
    const int screenWidth = 1024;
    const int screenHeight = 768;
    InitWindow(screenWidth, screenHeight, "Dashboard");

    // Define panels
    DashboardPanel panels[] = {
        {{20, 20, 300, 200}, "Statistics", LIGHTGRAY},
        {{340, 20, 300, 200}, "Performance", SKYBLUE},
        {{660, 20, 300, 200}, "Status", PINK},
        {{20, 240, 300, 200}, "Information", GREEN},
        {{340, 240, 300, 200}, "Metrics", PURPLE},
        {{660, 240, 300, 200}, "Overview", ORANGE}};

    // Init serial
// #ifdef CE_WINDOWS
//     ceSerial com("\\\\.\\COM3", 9600, 8, 'N', 1); // Windows
// #else
//     ceSerial com("/dev/ttyS0", 9600, 8, 'N', 1); // Linux
// #endif

    bool successFlag;
    string serialBuffer;
    int arduinoValue = 0;
    string arduinoStatus = "UNKNOWN";

    // if (com.Open() != 0) {
    //     CloseWindow();
    //     return 1;
    // }

    int sampleValue = 0;
    float sampleProgress = 0;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        sampleValue++;
        if (sampleValue > 100)
            sampleValue = 0;

        sampleProgress += 0.002f;
        if (sampleProgress > 1.0f)
            sampleProgress = 0.0f;

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw each panel
        for (const auto &panel : panels)
        {
            DrawRectangleRec(panel.bounds, panel.backgroundColor);
            DrawRectangleLinesEx(panel.bounds, 2, BLACK);
            DrawText(panel.title, panel.bounds.x + 10, panel.bounds.y + 10, 20, BLACK);
        }

        // Draw sample content in panels
        // Statistics Panel
        DrawText(TextFormat("Value: %d", sampleValue), 30, 60, 20, BLACK);
        DrawRectangle(30, 90, 280, 20, GRAY);
        DrawRectangle(30, 90, (int)(280 * sampleProgress), 20, BLUE);

        // Performance Panel
        DrawCircle(490, 120, 60, DARKBLUE);
        DrawCircle(490, 120, 50, RAYWHITE);
        DrawText(TextFormat("%d%%", sampleValue), 470, 110, 20, BLACK);

        // Status Panel
        const char *status = (sampleValue > 50) ? "ONLINE" : "OFFLINE";
        DrawText(status, 680, 100, 30, BLACK);
        //gewoon test
        // Draw footer
        DrawText("Dashboard Demo - Press ESC to exit", 10, screenHeight - 30, 20, DARKGRAY);

        // Panel 3: Status
        DrawText(arduinoStatus.c_str(), 680, 100, 30, BLACK);

        DrawText("Dashboard met Arduino - ESC om af te sluiten", 10, screenHeight - 30, 20, DARKGRAY);
        EndDrawing();
    }

   // com.Close();
    CloseWindow();

    return 0;
}
