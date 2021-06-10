//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "TargetObject.h"
#include "../Engine/headers/MatrixFactory.h"

TargetObject::TargetObject() : TargetObject({{1, 0, 1},}) {
    this->data = MatrixFactory::GetCubeMatrix(1, 1, 1).data;
}

TargetObject::TargetObject(const vector<Point3d> &points) : Matrix3d(points) {

}

void TargetObject::Update(float elapsedTime) {

    secondsExpired += (elapsedTime / 1000);

    if (secondsExpired > MAX_PULSE_SECONDS) {
        pulse = !pulse;
        secondsExpired = 0;
    }

    auto result = elapsedTime / 2500;
    float scaleWith;

    if (pulse) {
        scaleWith = 1 + result;
    } else {
        scaleWith = 1 - result;

    }

    this->scaleMatrixXYZCenter(scaleWith, scaleWith, scaleWith);

}

