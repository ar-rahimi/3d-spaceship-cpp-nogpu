//
// Created by Ahmad Rahimi on 2/25/18.
//

#ifndef SHOOTER_ACTIONROLLRIGHT_H
#define SHOOTER_ACTIONROLLRIGHT_H


#include "MatrixActionInterface.h"

class ActionRollRight : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONROLLRIGHT_H
