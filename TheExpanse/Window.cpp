#include "Window.h"
#include <iostream>

Window::Window(int width, int height, float s, float o) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        680, 480,
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

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Window::renderPresent() {
    SDL_RenderPresent(renderer);
}
