#include <SDL.h>
#include "Vector.h"
#include "TwoDObject.h"
#include "ThreeDObject.h"
#include <map>
#include <string>

#pragma once
class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Rect> viewportMap;
	float offset;

public:
	float scale;
	Window(int width, int height, float s, float o);
	void drawRect(float width, float height, float x, float y);
	void clear();
	void renderPresent();
	void drawLine(const Vector& start, const Vector& end, bool highlighted);
	void drawLine(const Vector& end);
	void drawTwoDObject(const TwoDObject& object, std::string face = "front");
	void drawThreeDObject(const ThreeDObject& object, std::string face = "front");
	void addViewport(std::string key, double width, double height, double x, double y);
	void renderSetViewport(std::string key);
};

