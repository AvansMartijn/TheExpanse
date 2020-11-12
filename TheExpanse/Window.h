#include <SDL.h>

#pragma once
class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Window(int width, int height);
	void drawRect(float width, float height, float x, float y);
	void clear();
	void renderPresent();
};

