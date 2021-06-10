//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONPITCH_H
#define SHOOTER_ACTIONPITCH_H


#include "../handlers/MatrixActionInterface.h"

class ActionPitch : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONPITCH_H
