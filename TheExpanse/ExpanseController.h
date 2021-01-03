

#pragma once
#include "ThreeDWindow.h"
#include "Scene.h"
#include "Window.h"
#include <vector>
#include "Matrix.h"
#include "ExpanseHelper.h"
#include "ThreeDObject.h"
#include "ThreeDWindow.h"
#include "Spaceship.h"
#include "Cube.h"
#include "Scene.h"
#include "Icosahedron.h"
#include <iostream>
#include <SDL.h>
class ExpanseController
{
private:
	ThreeDWindow window{ 1080, 720 };
	Scene scene;
	ExpanseHelper helper;
	bool showBoundingBoxes;
	void drawStuff();
	void onTick();
	void reset();
	void handlePlayerControls();
public:
	void initWorld();
	void programLoop();


};

