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
#include "ThreeDObject.h"
#include "ThreeDWindow.h"

ThreeDWindow window{ 1080, 720 };

ExpanseHelper helper;
TwoDObject tdobj;
ThreeDObject threedobj;


void drawStuff() {

    window.clear();
    window.renderPresent();
    // Render the rect to the screen
   /* window.clear();
    window.renderSetViewport("topLeft");
    drawGraph();
    window.drawThreeDObject(threedobj);
    window.renderSetViewport("topRight");
    drawGraph();
    window.drawThreeDObject(threedobj, "right");
    window.renderSetViewport("bottomLeft");
    drawGraph();
    window.drawThreeDObject(threedobj, "top");
   
    window.renderPresent();*/

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
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_KP_PLUS)
                {
                    // A has been pressed
                    threedobj = helper.scaleOnLocation(threedobj, 2, 2, 2);

                }
                if (event.key.keysym.sym == SDLK_KP_MINUS)
                {
                    // A has been pressed
                    threedobj = helper.scaleOnLocation(threedobj, 0.5, 0.5, 0.5);
                }
                if (event.key.keysym.sym == SDLK_UP)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, 0, 0.5, 0);

                }
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, 0, -0.5, 0);

                }
                if (event.key.keysym.sym == SDLK_LEFT)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, -0.5, 0, 0);


                }
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, 0.5, 0, 0);

                }
                if (event.key.keysym.sym == SDLK_1)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, 0, 0, 0.5);

                }
                if (event.key.keysym.sym == SDLK_2)
                {
                    // A has been pressed
                    threedobj = helper.translateMatrix(threedobj, 0, 0, -0.5);

                }
                if (event.key.keysym.sym == SDLK_x)
                {
                    // R has been pressed
                    threedobj = helper.rotate(threedobj, 45, 'X');

                }
                if (event.key.keysym.sym == SDLK_y)
                {
                    // E has been pressed
                    threedobj = helper.rotate(threedobj, 45, 'Y');

                }
                if (event.key.keysym.sym == SDLK_z)
                {
                    // T has been pressed
                    threedobj = helper.rotate(threedobj, 45, 'Z');

                }
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
