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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}



void ThreeDWindow::renderPresent() {
    SDL_RenderPresent(renderer);
}

void ThreeDWindow::drawObject(const ThreeDObject& object) {

    ThreeDObject persObject = camera.createPerspective(object);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
   /* double offset = 200;
    double scale = 20;*/

    for (int i = 0; i < object.lines.size(); i++) {

        /*if (persObject.lines[i].end.w < 0 && persObject.lines[i].end.w < 0) {
            continue;
        }*/
        
        double xS = persObject.points[persObject.lines[i].start].x;
        double yS = persObject.points[persObject.lines[i].start].y;
        double xE = persObject.points[persObject.lines[i].end].x;
        double yE = persObject.points[persObject.lines[i].end].y;

        /*int xStart = (int)(offset + (xS * scale));
        int yStart = (int)(offset + (yS * -1 * scale));
        int xEnd = (int)(offset + (xE * scale));
        int yEnd = (int)(offset + (yE * -1 * scale));*/
        if (persObject.points[persObject.lines[i].start].w > 0 && persObject.points[persObject.lines[i].end].w > 0) {
            SDL_RenderDrawLine(renderer, xS, yS, xE, yE);
        }
        //SDL_RenderDrawLine(renderer, xStart, yStart, xEnd, yEnd);
    }

    SDL_RenderDrawLine(renderer, persObject.centerPoint.x - 1, persObject.centerPoint.y + 1, persObject.centerPoint.x + 1, persObject.centerPoint.y - 1);
    SDL_RenderDrawLine(renderer, persObject.centerPoint.x - 1, persObject.centerPoint.y - 1, persObject.centerPoint.x + 1, persObject.centerPoint.y + 1);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
