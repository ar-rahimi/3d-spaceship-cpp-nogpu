//
// Created by Ahmad Rahimi on 2/23/18.
//

#ifndef SHOOTER_ACTIONROLL_H
#define SHOOTER_ACTIONROLL_H


#include "../handlers/MatrixActionInterface.h"

class ActionRoll : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONROLL_H
