#include <SDL.h>
#include "Vector.h"

#pragma once
class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	float offset;
	float scale;

public:
	Window(int width, int height);
	void drawRect(float width, float height, float x, float y);
	void clear();
	void renderPresent();
	void drawLine(const Vector& start, const Vector& end, bool highlighted);
};

