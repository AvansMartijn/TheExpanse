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

    for (int i = 0; i < object.lines.size(); i++) {

        double xS = persObject.points[persObject.lines[i].start].x;
        double yS = persObject.points[persObject.lines[i].start].y;
        double xE = persObject.points[persObject.lines[i].end].x;
        double yE = persObject.points[persObject.lines[i].end].y;
       
        if (persObject.points[persObject.lines[i].start].w > 0 && persObject.points[persObject.lines[i].end].w > 0) {
            SDL_RenderDrawLine(renderer, xS, yS, xE, yE);
        }
    }

    if (persObject.centerPoint.w > 0) {
        SDL_RenderDrawLine(renderer, persObject.centerPoint.x - 1, persObject.centerPoint.y + 1, persObject.centerPoint.x + 1, persObject.centerPoint.y - 1);
        SDL_RenderDrawLine(renderer, persObject.centerPoint.x - 1, persObject.centerPoint.y - 1, persObject.centerPoint.x + 1, persObject.centerPoint.y + 1);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ThreeDWindow::drawAABB(const ThreeDObject& object)
{
    ExpanseHelper helper;
    AABB AABB = object.AABB;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    ThreeDObject boundingBox;
    Vector min = AABB.min;
    Vector max = AABB.max;
    Vector mina = { min.x, min.y, min.z };//0/
    Vector minb = { min.x, max.y, min.z };//1/
    Vector minc = { min.x, min.y, max.z };//2/
    Vector mind = { min.x, max.y, max.z };//3
    Vector maxa = { max.x, min.y, min.z };//4
    Vector maxb = { max.x, max.y, min.z };//5
    Vector maxc = { max.x, min.y, max.z };//6
    Vector maxd = { max.x, max.y, max.z };//7


    boundingBox.points.clear();
    boundingBox.points.push_back(mina);
    boundingBox.points.push_back(minb);
    boundingBox.points.push_back(minc);
    boundingBox.points.push_back(mind);
    boundingBox.points.push_back(maxa);
    boundingBox.points.push_back(maxb);
    boundingBox.points.push_back(maxc);
    boundingBox.points.push_back(maxd);

    boundingBox.lines.clear();
    //0 goes to
    boundingBox.lines.push_back({ 0, 1 });
    boundingBox.lines.push_back({ 0, 2 });
    boundingBox.lines.push_back({ 0, 4 });
    //1 goes to
    boundingBox.lines.push_back({ 1, 3 });
    boundingBox.lines.push_back({ 1, 5 });
    //2 goes to
    boundingBox.lines.push_back({ 2, 3});
    boundingBox.lines.push_back({ 2, 6});
    //3
    boundingBox.lines.push_back({ 3, 7 });
    boundingBox.lines.push_back({ 4, 6 });
    boundingBox.lines.push_back({ 4, 5 });
    boundingBox.lines.push_back({ 7, 6 });
    boundingBox.lines.push_back({ 7, 5 });

    ThreeDObject persObject = camera.createPerspective(boundingBox);
    for (int i = 0; i < persObject.lines.size(); i++) {
        double xS = persObject.points[persObject.lines[i].start].x;
        double yS = persObject.points[persObject.lines[i].start].y;
        double xE = persObject.points[persObject.lines[i].end].x;
        double yE = persObject.points[persObject.lines[i].end].y;
        if (persObject.points[persObject.lines[i].start].w > 0 && persObject.points[persObject.lines[i].end].w > 0) {
            SDL_RenderDrawLine(renderer, xS, yS, xE, yE);
        }

    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

}
