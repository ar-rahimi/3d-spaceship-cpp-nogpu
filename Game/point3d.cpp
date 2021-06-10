//
// Created by Ahmad Rahimi on 2/21/18.
//

#include <cmath>
#include <iostream>
#include "point3d.h"
#include "Camera.h"
#include "../Engine/headers/RenderManager.h"

Point3d::Point3d(float x, float y, float z) {
    setX(x);
    setY(y);
    setZ(z);
    setW(1);
}

Point3d::Point3d(float x, float y, float z, float w) {
    setX(x);
    setY(y);
    setZ(z);
    setW(w);
}

void Point3d::setX(float x) {
    Point3d::x = x;
}

void Point3d::setY(float y) {
    Point3d::y = y;
}

void Point3d::setZ(float z) {
    Point3d::z = z;
}

void Point3d::setW(float w) {
    Point3d::w = w;
};

void Point3d::drawToPoint(const Point3d endPoint) {

}

Point3d Point3d::getNormalized() {
    float length = sqrtf(x * x + y * y + z * z + w * w);
    Point3d p = {x / length, y / length, z / length, w / length};
    if( p.x != p.x ) {
        p.x = 0;
    }
    if( p.y != p.y) {
        p.y = 0;
    }
    if( p.z != p.z ) {
        p.z = 0;
    }
    if( p.w != p.w ) {
        p.w = 0;
    }
    return p;
}

Point3d Point3d::operator*(const Point3d &other) {
    return {other.x * this->x, other.y * this->y, other.z * this->z, other.w * this->w};
}

Point3d Point3d::operator-(const Point3d &other) {
    return {this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w};
}

Point3d Point3d::operator+(const Point3d &other) {
    return {this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w};
}

void Point3d::logPoint() {
    std::cout << "x: " << x << ", y: " << y << ", z: " << z << ", w:" << w << std::endl;
}

Point Point3d::convertTo2dPoint(float distance) {
    const Camera *cam = &RenderManager::GetCamera();
    x -= cam->position.x;
    y -= cam->position.y;
    z -= cam->position.z;
    float f = distance / z;
    return Point(x * f, y * f);
}

Point3d Point3d::getPointOn2dCanvas() {
    return Point3d(0, 0, 0);
}

Point3d Point3d::operator*(const float other) {
    return Point3d(x * other, y * other, z * other);
}

Point3d Point3d::operator/(const float &divideBy) {
    return Point3d(x / divideBy, y / divideBy, z / divideBy);
}

float Point3d::GetInProduct(Point3d a, Point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3d Point3d::GetOutProduct(Point3d a, Point3d b) {
    return Point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}

float Point3d::GetDotProduct(Point3d a, Point3d b) {
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

float Point3d::GetMagnitude(Point3d a) {
    return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

float Point3d::GetTotal(Point3d a) {
    return a.x+a.y+a.z;
}

float Point3d::GetDistance(Point3d a, Point3d b) {
    return sqrtf((a.x-b.x)*(a.x-b.x) + (a.x-b.x)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}
