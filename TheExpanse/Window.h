#include <SDL.h>
#include "Vector.h"
#include "TwoDObject.h"

#pragma once
class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	float offset;

public:
	float scale;
	Window(int width, int height, float s, float o);
	void drawRect(float width, float height, float x, float y);
	void clear();
	void renderPresent();
	void drawLine(const Vector& start, const Vector& end, bool highlighted);
	void drawLine(const Vector& end);
	void drawTwoDObject(const TwoDObject& object);
};

