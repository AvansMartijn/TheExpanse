#include "ThreeDWindow.h"

ThreeDWindow::ThreeDWindow(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("The Expanse",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void ThreeDWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}



void ThreeDWindow::renderPresent() {
    SDL_RenderPresent(renderer);
}

void ThreeDWindow::drawObject(const ThreeDObject& object) {

}
