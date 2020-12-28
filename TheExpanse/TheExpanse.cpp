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
    window.drawObject(threedobj);
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
                //if (event.key.keysym.sym == SDLK_UP)
                //{
                //    // A has been pressed
                //    threedobj = helper.translateMatrix(threedobj, 0, 0.5, 0);

                //}
                //if (event.key.keysym.sym == SDLK_DOWN)
                //{
                //    // A has been pressed
                //    threedobj = helper.translateMatrix(threedobj, 0, -0.5, 0);

                //}
                //if (event.key.keysym.sym == SDLK_LEFT)
                //{
                //    // A has been pressed
                //    threedobj = helper.translateMatrix(threedobj, -0.5, 0, 0);


                //}
                //if (event.key.keysym.sym == SDLK_RIGHT)
                //{
                //    // A has been pressed
                //    threedobj = helper.translateMatrix(threedobj, 0.5, 0, 0);

                //}
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
                //PITCH bACK
                if (event.key.keysym.sym == SDLK_s)
                {
                    // R has been pressed
                    threedobj = helper.rotate(threedobj, 3, 'X');

                }

                //PITCH forward
                if (event.key.keysym.sym == SDLK_w)
                {
                    // R has been pressed
                    threedobj = helper.rotate(threedobj, -3, 'X');

                }
                //JAW RIGHT
                if (event.key.keysym.sym == SDLK_d)
                {
                    // E has been pressed
                    threedobj = helper.rotate(threedobj, 3, 'Y');

                }

                //JAW left
                if (event.key.keysym.sym == SDLK_a)
                {
                    // E has been pressed
                    threedobj = helper.rotate(threedobj, -3, 'Y');

                }
                //ROLL RIGHT
                if (event.key.keysym.sym == SDLK_e)
                {
                    // T has been pressed
                    threedobj = helper.rotate(threedobj, 3, 'Z');

                }

                //ROLL LEFT
                if (event.key.keysym.sym == SDLK_q)
                {
                    // T has been pressed
                    threedobj = helper.rotate(threedobj, -3, 'Z');

                }
                //CAMERA UP
                if (event.key.keysym.sym == SDLK_PAGEUP)
                {
                    // T has been pressed
                    window.camera.eye = window.camera.eye - window.camera.up;


                }
                //CAMERA DOWN
                if (event.key.keysym.sym == SDLK_PAGEDOWN)
                {
                    // T has been pressed
                    window.camera.eye = window.camera.eye + window.camera.up;


                }
                //camera forward
                if (event.key.keysym.sym == SDLK_UP)
               {
                   // A has been pressed
                   //window.camera.eye = helper.getTranslationMatrix(0, 0, -0.5) * window.camera.eye;
                    window.camera.eye = window.camera.eye - window.camera.direction;
               }
                //camera backward
               if (event.key.keysym.sym == SDLK_DOWN)
               {
                   // A has been pressed
                   window.camera.eye = window.camera.eye + window.camera.direction;
               }
               //camera left
               if (event.key.keysym.sym == SDLK_LEFT)
               {
                   // A has been pressed
                   //window.camera.eye = helper.getTranslationMatrix(-0.5, 0, 0) * window.camera.eye;
                   window.camera.eye = window.camera.eye + window.camera.right;


               }
               //camera right
               if (event.key.keysym.sym == SDLK_RIGHT)
               {
                   // A has been pressed
                   window.camera.eye = window.camera.eye - window.camera.right;



               }
               if (event.key.keysym.sym == SDLK_LSHIFT) {
                   Vector v = threedobj.getDirectionVector();
                   v = helper.normalize(v);
                   threedobj = helper.translateMatrix(threedobj, v.x,  v.y,  v.z);
               }
            }
         
        }
        drawStuff();
    }
}


int main()
{
    //threedobj = helper.translateMatrix(threedobj,0, 0, -10);
    
   
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
