//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONSCALEDOWN_H
#define SHOOTER_ACTIONSCALEDOWN_H


#include "../handlers/MatrixActionInterface.h"

class ActionScaleDown : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONSCALEDOWN_H
