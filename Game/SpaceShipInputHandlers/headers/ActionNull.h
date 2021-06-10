//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONNULL_H
#define SHOOTER_ACTIONNULL_H


#include "../handlers/MatrixActionInterface.h"

class ActionNull : public MatrixActionInterface {

    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONNULL_H
