//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONMOVERIGHT_H
#define SHOOTER_ACTIONMOVERIGHT_H


#include "../handlers/MatrixActionInterface.h"

class ActionMoveRight : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};



#endif //SHOOTER_ACTIONMOVERIGHT_H
