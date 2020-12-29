#include "Window.h"
#include <iostream>

Window::Window(int width, int height, float s, float o) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("The Expanse",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    offset = o;
    scale = s;
}

void Window::drawRect(float width, float height, float x, float y) {
    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = scale * x;
    r.y = scale * y;
    r.w = scale * width;
    r.h = scale * height;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Render rect
    SDL_RenderFillRect(renderer, &r);
}

void Window::drawLine(const Vector& start, const Vector& end, bool highlighted) {
    if (highlighted) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    SDL_RenderDrawLine(renderer, offset + (start.x * scale ), offset + (start.y * scale), offset + (end.x * scale), offset + (end.y * scale));
}

void Window::drawLine(const Vector& end) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, offset + 0, offset + 0, offset + (end.x * scale), offset + ((end.y * -1) * scale));
}

void Window::drawTwoDObject(const TwoDObject& object, std::string face)
{
    /*SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = 0; i < object.lines.size(); i++) {
        double xS = 0;
        double yS = 0;
        double xE = 0;
        double yE = 0;
        if (face == "top") {
            double xS = object.lines[i].start.x;
            double yS = object.lines[i].start.z;
            double xE = object.lines[i].end.x;
            double yE = object.lines[i].end.z;
        }
        else if (face == "right") {
            double xS = object.lines[i].start.z;
            double yS = object.lines[i].start.y;
            double xE = object.lines[i].end.z;
            double yE = object.lines[i].end.y;

        }
        else {
            double xS = object.lines[i].start.x;
            double yS = object.lines[i].start.y;
            double xE = object.lines[i].end.x;
            double yE = object.lines[i].end.y;
        }

        int xStart = (int)(offset + (xS * scale));
        int yStart = (int)(offset + (yS * -1 * scale));
        int xEnd = (int)(offset + (xE * scale));
        int yEnd = (int)(offset + (yE * -1 * scale));
        SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);*/

}

void Window::drawThreeDObject(const ThreeDObject& object, std::string face)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = 0; i < object.lines.size(); i++) {
        double xS = 0;
        double yS = 0;
        double xE = 0;
        double yE = 0;
       /* if (face == "top") {
            xS = object.lines[i].start.x;
            yS = object.lines[i].start.z;
            xE = object.lines[i].end.x;
            yE = object.lines[i].end.z;
        }
        else if (face == "right") {
            xS = object.lines[i].start.z;
            yS = object.lines[i].start.y;
            xE = object.lines[i].end.z;
            yE = object.lines[i].end.y;

        }
        else {
            xS = object.lines[i].start.x;
            yS = object.lines[i].start.y;
            xE = object.lines[i].end.x;
            yE = object.lines[i].end.y;
        }*/

        int xStart = (int)(offset + (xS * scale));
        int yStart = (int)(offset + (yS * -1 * scale));
        int xEnd = (int)(offset + (xE * scale));
        int yEnd = (int)(offset + (yE * -1 * scale));
        SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
}



void Window::renderPresent() {
    SDL_RenderPresent(renderer);
}

void Window::addViewport(std::string key, double width, double height, double x, double y) {
    SDL_Rect rect;
    rect.w = width;
    rect.h = height;
    rect.x = x;
    rect.y = y;
    viewportMap.insert(std::pair<std::string, SDL_Rect>(key, rect));
}

void Window::renderSetViewport(std::string key) {
    SDL_Rect rect = viewportMap.at(key);
    SDL_RenderSetViewport(renderer, &rect);
}
