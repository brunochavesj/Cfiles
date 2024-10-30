#include "raylib.h"
#include <string.h>

#define MAX_NAME_LENGTH 50

int
main ()
{
  // Initialize the screen dimensions
  const int screenWidth = 800;
  const int screenHeight = 450;

  // Initialize raylib window
  InitWindow (screenWidth, screenHeight, "Enter Your Name");

  // Variables to store user input
  char name[MAX_NAME_LENGTH] = { 0 };
  int letterCount = 0;
  bool enterPressed = false;

  SetTargetFPS (60); // Set desired frame rate

  // Main application loop
  while (!WindowShouldClose ())
    {
      // Check for key inputs if enter hasn't been pressed
      if (!enterPressed)
        {
          int key = GetCharPressed (); // Get pressed key character

          // Process character inputs within the max length
          if ((key >= 32 && key <= 125) && (letterCount < MAX_NAME_LENGTH - 1))
            {
              name[letterCount] = (char)key;
              letterCount++;
            }

          // Backspace key removes last character
          if (IsKeyPressed (KEY_BACKSPACE) && letterCount > 0)
            {
              letterCount--;
              name[letterCount] = '\0';
            }

          // Enter key finishes input
          if (IsKeyPressed (KEY_ENTER) && letterCount > 0)
            {
              enterPressed = true;
            }
        }

      // Start drawing
      BeginDrawing ();
      ClearBackground (RAYWHITE);

      // Draw instructions and input box
      DrawText ("What is your name?", 190, 140, 20, DARKGRAY);
      DrawRectangle (190, 180, 400, 50, LIGHTGRAY);
      DrawText (name, 200, 195, 20, BLACK);

      if (enterPressed)
        {
          // Display the user's name if Enter was pressed
          DrawText (TextFormat ("Your name is: %s", name), 190, 260, 20,
                    DARKGREEN);
        }
      else
        {
          // Prompt the user to type and press Enter
          DrawText ("Press [ENTER] when done.", 190, 240, 20, GRAY);
        }

      EndDrawing ();
    }

  // Clean up and close window
  CloseWindow ();
  return 0;
}
