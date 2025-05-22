#include "raylib.h"
#include "ceserial.h"
#include <string>
#include <sstream>

using namespace std;

struct DashboardPanel {
    Rectangle bounds;
    const char* title;
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
        { { 20, 20, 300, 200 }, "Statistics", LIGHTGRAY },
        { { 340, 20, 300, 200 }, "Performance", SKYBLUE },
        { { 660, 20, 300, 200 }, "Status", PINK },
    };

    // Init serial
#ifdef CE_WINDOWS
    ceSerial com("\\\\.\\COM3", 9600, 8, 'N', 1); // Windows
#else
    ceSerial com("/dev/ttyS0", 9600, 8, 'N', 1); // Linux
#endif

    bool successFlag;
    string serialBuffer;
    int arduinoValue = 0;
    string arduinoStatus = "UNKNOWN";

    if (com.Open() != 0) {
        CloseWindow();
        return 1;
    }

    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose())
    {
        // === LEES SERIAL DATA VAN ARDUINO ===
        while (com.Peek() > 0) {
            char c = com.ReadChar(successFlag);
            if (successFlag) {
                if (c == '\n') {
                    // Einde van bericht
                    istringstream iss(serialBuffer);
                    iss >> arduinoValue; // verwacht een int, bv. "42\n"
                    arduinoStatus = (arduinoValue > 50) ? "ONLINE" : "OFFLINE";
                    serialBuffer.clear();
                } else {
                    serialBuffer += c;
                }
            }
        }

        // === TEKEN DASHBOARD ===
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const auto& panel : panels) {
            DrawRectangleRec(panel.bounds, panel.backgroundColor);
            DrawRectangleLinesEx(panel.bounds, 2, BLACK);
            DrawText(panel.title, panel.bounds.x + 10, panel.bounds.y + 10, 20, BLACK);
        }

        // Panel 1: Statistics
        DrawText(TextFormat("Arduino Value: %d", arduinoValue), 30, 60, 20, BLACK);
        DrawRectangle(30, 90, 280, 20, GRAY);
        DrawRectangle(30, 90, (int)(280 * (arduinoValue / 100.0f)), 20, BLUE);

        // Panel 2: Performance
        DrawCircle(490, 120, 60, DARKBLUE);
        DrawCircle(490, 120, 50, RAYWHITE);
        DrawText(TextFormat("%d%%", arduinoValue), 470, 110, 20, BLACK);

        // Panel 3: Status
        DrawText(arduinoStatus.c_str(), 680, 100, 30, BLACK);

        DrawText("Dashboard met Arduino - ESC om af te sluiten", 10, screenHeight - 30, 20, DARKGRAY);
        EndDrawing();
    }

    com.Close();
    CloseWindow();

    return 0;
}
