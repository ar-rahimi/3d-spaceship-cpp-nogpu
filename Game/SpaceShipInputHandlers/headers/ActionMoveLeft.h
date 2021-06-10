//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONMOVELEFT_H
#define SHOOTER_ACTIONMOVELEFT_H


#include "../handlers/MatrixActionInterface.h"

class ActionMoveLeft : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONMOVELEFT_H
