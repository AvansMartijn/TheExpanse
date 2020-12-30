#include <SDL.h>
#include "ThreeDObject.h"
#include "Camera.h"


#pragma once
class ThreeDWindow
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Camera camera;
	ThreeDWindow(int width, int height);
	void renderPresent();
	void clear();
	void drawObject(const ThreeDObject& object);
	void drawAABB(const ThreeDObject& object);

};

