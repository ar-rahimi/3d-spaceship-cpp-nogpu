//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONMOVEBOTTOM_H
#define SHOOTER_ACTIONMOVEBOTTOM_H


#include "../handlers/MatrixActionInterface.h"

class ActionTurnDown : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONMOVEBOTTOM_H
