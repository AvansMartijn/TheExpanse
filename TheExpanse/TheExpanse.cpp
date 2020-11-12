// TheExpanse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SDL.h>
#undef main
#include "Window.h"


Window window{1080, 720};
float offset = 100.0f;
float scale = 20.0f;

void drawGraph() {
    for (int i =-5; i < 6; i++) {
        bool highlighted = false;
        if (i == 0) {
            highlighted = true;
        }
        //x scale
        window.drawLine(Vector{ offset + (i * scale), 0}, Vector{ offset + (i * scale), offset + (5 * scale) }, highlighted);
        // y scale
        window.drawLine(Vector{ 0, offset + (i * scale) }, Vector{ offset + (5 * scale), offset + (i * scale) }, highlighted);
    }
}
void drawStuff() {
    // Render the rect to the screen
    window.clear();
    /*window.drawRect(50, 50, 50, 50);
    window.drawLine(Vector{ 50, 50 }, Vector{ 200, 250 });*/
    //window.drawRect(5, 5, 0 + offset, 0 + offset);

    //TODO FIX OFFSETS AND SCALES TO PAINTING

    //Vec A
    Vector vecA{ (2 * scale) + offset,(3 * scale * -1) + offset };
    window.drawLine(Vector{ 0 + offset ,0 + offset }, vecA, false);

    //Vec B
    Vector vecB{ (1 * scale) + offset,(-3 * scale * -1) + offset };
    window.drawLine(Vector{ 0 + offset ,0 + offset }, vecB, false);

    //Vec A + B
    window.drawLine(Vector{ 0 + offset ,0 + offset }, vecB+vecA, false);

    drawGraph();
    window.renderPresent();
}

void programLoop() {
    
    while (true)
    {
        // Get the next event
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                // Break out of the loop on quit
                break;
            }
        }
        drawStuff();
    }
}


int main()
{
    programLoop();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
