//
// Created by Ahmad Rahimi on 2/23/18.
//

#ifndef SHOOTER_MATRIXFACTORY_H
#define SHOOTER_MATRIXFACTORY_H


#include "../../Game/Matrix3d.h"

static class MatrixFactory {


public:
    static Matrix3d GetCubeMatrix(float xScale, float yScale, float zScale);

    static Matrix3d GetTriangleMatrix(float xScale, float yScale, float zScale);

    static Matrix3d GetShipMatrix(float xScale, float yScale, float zScale);

    static Matrix3d GetBulletMatrix(float xScale, float yScale, float zScale);
};


#endif //SHOOTER_MATRIXFACTORY_H
