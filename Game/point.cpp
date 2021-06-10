//
// Created by Ahmad Rahimi on 11/12/17.
//
#include <SDL_render.h>
#include <vector>
#include "point.h"
#include "../Engine/headers/RenderManager.h"

Point::Point(float x, float y) :
        x{x},
        y{y} {

}

void Point::setX(float x) {
    Point::x = x;
}

void Point::setY(float y) {
    Point::y = y;
}

void Point::drawTo(Point &endPoint) {
    SDL_RenderDrawLine(RenderManager::Instance()->GetRenderer(), x,
                       y, endPoint.x, endPoint.y);
}

void Point::logPoint() {
    std::cout << "x: " << x << ", y: " << y << std::endl;
}



