//
// Created by Ahmad Rahimi on 11/12/17.
//

#ifndef SHOOTER_POINT_H
#define SHOOTER_POINT_H

#include "../Engine/headers/Drawable.h"

class Point {

private:
    Point *endPoint;

public:
    Point(float x, float y);

    float x, y;

    void setX(float x);

    void setY(float y);

    void drawTo(Point &endPoint);

    void logPoint();
};

#endif //SHOOTER_POINT_H
