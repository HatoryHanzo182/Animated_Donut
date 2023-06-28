#include "Header.h"

using namespace std;

/*
     * 
     * This code implements a pseudo animation of the donut rotating and displaying it in the console.
     *
     * It uses ASCII characters to create the effect of a 3D object,
     * which is rotated and displayed on the console screen.
     * 
     * The code consists of the following main elements:
     * 
     * 1. Defining the RemoveCursor() function, which hides the blinking cursor in the console.
     * 2. Definition of the main() function, which is the entry point to the program.
     * 3. Initialize the variables and arrays needed to animate and display the donut.
     * 4. Clearing the console screen with the command printf("\x1b[2J").
     * 5. Infinite while (true) loop which ensures continuous animation.
     * 6. Filling arrays b and z with certain values using the memset function.
     * 7. Nested loops to generate character values and donut display depth.
     *    Inside the loops, various parameters are calculated and the condition is checked
     *    displaying a character at a particular position.
     * 8. Move the cursor to the beginning of the screen using the printf("\x1b[2H") command.
     * 9. A loop for displaying characters on the screen using the putchar function.
     *    Inside the loop, the animation parameters are also changed.
     * 10. Delay animation using the Sleep function.
     * 11. Return value 0 from the main function.
     * 
     * This code creates a 3D spinning donut effect on the console screen
     * and demonstrates the use of ASCII characters to create simple animations.
     *


                      $@@@$$$$$@@@@$
                  $$$$#############$$$$
                #####***!!!***!****####$$$
              ###**!**!!!!====!!!!!****#####
            **#***!!!=;;;::::::;;;=!!!***####*
           ****!!!==;::~--,,,,--~::;=!!!******!
          !***!!!==::~,.........,-~:;;=!*******
          !**!!!!=;:--............-~:;==!!*****!
         ;!!*!!!!=;:-,..        ..,-:;==!!****!!
         ;!!*!!!!=;:~,.          .,~:;=!!!!**!!=
         :=!!*****!!=;:          -:;;=!!!!!*!!!=
         :=!!**********!        ;==!!!*!*!!!!!=;
          ;=!!***#########**!************!!!!!=:
          ~;=!!**###$$$$@@@$$$$$#####***!!!!!=;
           ~;=!!**###$$$@@@@@$$$$###****!!!==:-
            -:;=!****##$$$$$$$$###****!!!==;:-
              ~;==!!******####****!!!!!==;:-
               .-:;;=!!*!*!!!!*!!!!===;:~-
                  ,~~:;;;======;=;;::~-.
                      .,----~~~--,,.

*/

void RemoveCursor();

int main() 
{
    float A = 0;
    float B = 0;
    float i;
    float j;
    int k;
    float z[1760];
    char b[1760];

    RemoveCursor();

    printf("\x1b[2J");

    while (true)
    {
        // Filling arrays b and z.
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        // Loops to generate character values and display depth.
        for (j = 0; j < 6.28; j += 0.07) 
        {
            for (i = 0; i < 6.28; i += 0.02) 
            {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])  // Checking the condition for displaying a character at a specific position.
                {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[2H");

        for (k = 0; k < 1761; k++)  // Display characters on the screen.
        {
            putchar(k % 80 ? b[k] : 10);
            
            A += 0.00004;
            B += 0.00002;
        }
        Sleep(5);  // Delay for animation.
    }

    return 0;
}

void RemoveCursor()  // Function to hide the blinking cursor in the console.
{
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;

    GetConsoleCursorInfo(console_handle, &cursor_info);

    cursor_info.bVisible = false;

    SetConsoleCursorInfo(console_handle, &cursor_info);
}