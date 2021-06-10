//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONSHOOT_H
#define SHOOTER_ACTIONSHOOT_H


#include "../handlers/MatrixActionInterface.h"

class ActionShoot : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONSHOOT_H
