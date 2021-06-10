//
// Created by Ahmad Rahimi on 11/10/17.
//

#ifndef SHOOTER_MVECTOR_H
#define SHOOTER_MVECTOR_H

#include <SDL_system.h>
#include "../Engine/headers/RenderManager.h"
#include "point.h"
#include <stdlib.h>
#include <SDL_ttf.h>
class Vector {

private:
    int rgb[3];
    Point beginPoint = Point(0,0);
    Point lengthPoint = Point(0,0);
    void drawtext();
public:
    const static int SCALE = 2;

    Vector(){};

    Vector(Point beginPoint, Point endPoint);

    Vector calculate(Vector *other_vector, bool plus);

    void Draw();

    const Point &getBeginPoint() const;

    void setBeginPoint(const Point &beginPoint);

    const Point &getEndPoint() const;

    void setEndPoint(const Point &endPoint);

    float calcEndX();
    float calcEndY();

    Point getCalculatedEndPoint();
};

#endif //SHOOTER_MVECTOR_H
