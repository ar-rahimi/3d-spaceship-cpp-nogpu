//
// Created by Ahmad Rahimi on 2/21/18.
//

#ifndef SHOOTER_POINT3D_H
#define SHOOTER_POINT3D_H


#include "point.h"

class Point3d {
public:
    Point3d(float x, float y, float z);
    Point3d(float x, float y, float z, float w);
    float x, y, z, w;

    void setX(float x);

    void setY(float y);

    void setZ(float z);

    void setW(float w);

    Point3d getNormalized();

    void drawToPoint(const Point3d endPoint);

    Point3d operator*(const Point3d &other);

    Point3d operator/(const float &divideBy);

    Point3d operator*(const float multiplier);

    Point3d operator-(const Point3d& other);

    Point3d operator+(const Point3d& other);

    Point convertTo2dPoint(float distance);

    void logPoint();

    Point3d getPointOn2dCanvas();

    static float GetInProduct(Point3d a, Point3d b);

    static Point3d GetOutProduct(Point3d a, Point3d b);

    static float GetMagnitude(Point3d a);

    static float GetDotProduct(Point3d a, Point3d b);

    static float GetTotal(Point3d a);

    static float GetDistance(Point3d a, Point3d b);

};


#endif //SHOOTER_POINT3D_H
