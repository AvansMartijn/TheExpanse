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
#include "Spaceship.h"
#include "Cube.h"
#include "Scene.h"
#include "Icosahedron.h"

ThreeDWindow window{ 1080, 720 };
Scene scene;
ExpanseHelper helper;
//std::vector<ThreeDObject> objectList;


void drawStuff() {

	window.clear();
	for (const ThreeDObject& obj : scene.objectList)
	{
		window.drawObject(obj);
	}
	window.renderPresent();

}

void handlePlayerControls() {
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_KP_PLUS])
	{
		// A has been pressed
		scene.updatePlayerShip(helper.scaleOnLocation(scene.getPlayerShip(), 2, 2, 2));

	}
	if (keystate[SDL_SCANCODE_KP_MINUS])
	{
		// A has been pressed
		scene.updatePlayerShip(helper.scaleOnLocation(scene.getPlayerShip(), 0.5, 0.5, 0.5));
	}


	//PITCH bACK
	if (keystate[SDL_SCANCODE_S])
	{
		// R has been pressed
		scene.updatePlayerShip(helper.rotate(scene.getPlayerShip(), 3, 'X'));

	}

	//PITCH forward
	if (keystate[SDL_SCANCODE_W])
	{
		// R has been pressed
		scene.updatePlayerShip(helper.rotate(scene.getPlayerShip(), -3, 'X'));

	}
	//JAW RIGHT
	if (keystate[SDL_SCANCODE_D])
	{
		// E has been pressed
		scene.updatePlayerShip(helper.rotate(scene.getPlayerShip(), 3, 'Y'));

	}

	//JAW left
	if (keystate[SDL_SCANCODE_A])
	{
		// E has been pressed
		scene.updatePlayerShip(helper.rotate(scene.getPlayerShip(), -3, 'Y'));

	}
	//ROLL RIGHT
	if (keystate[SDL_SCANCODE_E])
	{
		// T has been pressed
		scene.updatePlayerShip(helper.roll(scene.getPlayerShip(), 3));

	}

	//ROLL LEFT
	if (keystate[SDL_SCANCODE_Q])
	{
		// T has been pressed
		scene.updatePlayerShip(helper.roll(scene.getPlayerShip(), -3));

	}
	//CAMERA UP
	if (keystate[SDL_SCANCODE_PAGEUP])
	{
		// T has been pressed
		window.camera.eye = window.camera.eye - window.camera.up;


	}
	//CAMERA DOWN
	if (keystate[SDL_SCANCODE_PAGEDOWN])
	{
		// T has been pressed
		window.camera.eye = window.camera.eye + window.camera.up;


	}
	//camera forward
	if (keystate[SDL_SCANCODE_UP])
	{
		// A has been pressed
		//window.camera.eye = helper.getTranslationMatrix(0, 0, -0.5) * window.camera.eye;
		window.camera.eye = window.camera.eye - window.camera.direction;
	}
	//camera backward
	if (keystate[SDL_SCANCODE_DOWN])
	{
		// A has been pressed
		window.camera.eye = window.camera.eye + window.camera.direction;
	}
	//camera left
	if (keystate[SDL_SCANCODE_LEFT])
	{
		// A has been pressed
		//window.camera.eye = helper.getTranslationMatrix(-0.5, 0, 0) * window.camera.eye;
		window.camera.eye = window.camera.eye - window.camera.right;


	}
	//camera right
	if (keystate[SDL_SCANCODE_RIGHT])
	{
		// A has been pressed
		window.camera.eye = window.camera.eye + window.camera.right;
	}
	if (keystate[SDL_SCANCODE_LSHIFT]) {
		Vector v = helper.getForwardVector(scene.getPlayerShip());
		v = helper.normalize(v);
		scene.updatePlayerShip(helper.translateMatrix(scene.getPlayerShip(),v.x, v.y, v.z));
	}
}

void onTick() {
	handlePlayerControls();
	scene.updateTarget(helper.pulseObject(scene.getTarget()));

}
void programLoop() {

	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;

	while (true)
	{
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60) {
			b = a;

			onTick();
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
}

void initWorld() {
	Spaceship theShip;
	Icosahedron target;
	ThreeDObject newTarget = helper.translateMatrix(target, 0, 0, -40);
	newTarget.pulseData.growCounter = 0;
	newTarget.pulseData.growMultiplier = 1.05;
	newTarget.pulseData.isGrowing = true;
	newTarget.pulseData.growTimes = 30;
	scene.setPlayerShip(theShip);
	scene.setTarget(newTarget);
	Cube body1;
	ThreeDObject newBody1 = helper.translateMatrix(body1, -10, 5, -30);
	Cube body2;
	ThreeDObject newBody2 = helper.translateMatrix(body1, 10, 5, -10);
	Cube body3;
	ThreeDObject newBody3 = helper.translateMatrix(body1, 7, 9, -5);
	Cube body4;
	ThreeDObject newBody4 = helper.translateMatrix(body1, -15, 30, -60);
	Cube body5;
	ThreeDObject newBody5 = helper.translateMatrix(body1, 8, -30, -20);
	Cube body6;
	ThreeDObject newBody6 = helper.translateMatrix(body1, 15, -10, -15);


	scene.objectList.push_back(newBody1);
	scene.objectList.push_back(newBody2);
	scene.objectList.push_back(newBody3);
	scene.objectList.push_back(newBody4);
	scene.objectList.push_back(newBody5);
	scene.objectList.push_back(newBody6);



}


int main()
{

	initWorld();
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
