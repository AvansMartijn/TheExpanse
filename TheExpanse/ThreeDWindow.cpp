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

    ThreeDObject persObject = camera.createPerspective(object);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < object.lines.size(); i++) {

        double xS = persObject.lines[i].start.x;
        double yS = persObject.lines[i].start.y;
        double xE = persObject.lines[i].end.x;
        double yE = persObject.lines[i].end.y;

        //int xStart = (int)(offset + (xS * scale));
        //int yStart = (int)(offset + (yS * -1 * scale));
        //int xEnd = (int)(offset + (xE * scale));
        //int yEnd = (int)(offset + (yE * -1 * scale));

        SDL_RenderDrawLine(renderer, xS, yS, xE, yE);
        //SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
