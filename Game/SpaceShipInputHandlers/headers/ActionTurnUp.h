//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONMOVETOP_H
#define SHOOTER_ACTIONMOVETOP_H


#include "../handlers/MatrixActionInterface.h"

class ActionTurnUp : public MatrixActionInterface {
private:
    float topSpeed = 0.01;
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONMOVETOP_H
