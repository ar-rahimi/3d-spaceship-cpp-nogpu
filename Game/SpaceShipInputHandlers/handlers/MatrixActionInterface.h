//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_MATRIX3DACTIONS_H
#define SHOOTER_MATRIX3DACTIONS_H


#include "../../Matrix3d.h"
#include "../../SpaceShip.h"

class MatrixActionInterface {

private:
    float elapsedTime;

public:
    MatrixActionInterface *setElapsedTime(float elapsedTime) {
        this->elapsedTime = elapsedTime;
        return this;
    }

    float getElapsedTime() {
        return this->elapsedTime;
    }

    virtual void handle(SpaceShip &object) = 0;

    virtual std::string getName() = 0;
};


#endif //SHOOTER_MATRIX3DACTIONS_H
