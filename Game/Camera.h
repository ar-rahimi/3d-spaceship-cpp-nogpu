//
// Created by Ahmad Rahimi on 2/22/18.
//

#ifndef SHOOTER_CAMERA_H
#define SHOOTER_CAMERA_H


#include "point3d.h"
#include "../Engine/headers/Controls.h"
#include "matrix.h"

class Camera {
private:

    float near = 50;
    float far = 100;
    float fov = 260;

public:
    bool follow = false;
    Point3d eye = Point3d(60,-80,-70,1);
    Point3d lookAt = Point3d(4.26370811,4.16553497,1,1);
    Point3d up = Point3d(0,-1,0,1);
    Camera(float x, float y, float z);

    Point3d position = {-600, -495, -5};

    void updatePosition(Controls dir);

    Matrix getProjectionMatrix();
    Matrix getCameraMatrix();
    Matrix correctViewMatrix(Matrix m);
    void handleEvents(Controls dir);
    void rotateCameraHor(Point pos, float rad);
    void rotateCameraVert(Point pos, float rad);
};


#endif //SHOOTER_CAMERA_H
