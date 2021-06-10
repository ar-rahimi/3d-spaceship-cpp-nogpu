//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_TARGETOBJECT_H
#define SHOOTER_TARGETOBJECT_H


#include "Matrix3d.h"

class TargetObject : public Matrix3d {


private:
    bool pulse = true;
    double secondsExpired;
    double const MAX_PULSE_SECONDS = 1;

public:
    TargetObject();

    explicit TargetObject(const vector<Point3d> &points);

    void Update(float elapsedTime) override;

};


#endif //SHOOTER_TARGETOBJECT_H
