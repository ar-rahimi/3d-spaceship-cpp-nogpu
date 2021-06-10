//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONSCALEUP_H
#define SHOOTER_ACTIONSCALEUP_H


#include "../handlers/MatrixActionInterface.h"

class ActionScaleUp : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONSCALEUP_H
