// TheExpanse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SDL.h>
#undef main
#include "Window.h"
#include <vector>
#include "Matrix.h"
//Helper Class
#include "ExpanseHelper.h"

Window window{1080, 720, 20.0f, 200.0f };
//float offset = 100.0f;
//float scale = 20.0f;

void drawGraph() {
    for (int i =-10; i < 11; i++) {
        bool highlighted = false;
        if (i == 0) {
            highlighted = true;
        }

        window.drawLine(Vector{ (float)i, -10 }, Vector{ (float)i, 10 }, highlighted);
        window.drawLine(Vector{ -10, (float)i }, Vector{ 10, (float)i}, highlighted);
    }
}
void drawStuff() {
    // Render the rect to the screen
    window.clear();
   
    //Vec A
   /* Vector vecA{ 2, 3 };
    window.drawLine(vecA + 3);*/

    ////Vec B
    //Vector vecB{ 1, -4 };
    //window.drawLine(vecB);

    //////Vec A + B
     //window.drawLine(vecA-vecB);
    drawGraph();

    ExpanseHelper helper;
    //Matrix translationMatrix = helper.getTranslationMatrix(-5, -5);
    Matrix translationMatrix = helper.getTranslationMatrix(0, 0);

    TwoDObject tdobj;
    for (int i = 0; i < tdobj.lines.size(); i++)
    {
        tdobj.lines[i] = { translationMatrix * std::get<0>(tdobj.lines[i]), translationMatrix * std::get<1>(tdobj.lines[i]) };
    }
    window.drawTwoDObject(tdobj);
   
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
