//
// Created by Ahmad Rahimi on 2/25/18.
//

#ifndef SHOOTER_ACTIONTURNLEFT_H
#define SHOOTER_ACTIONTURNLEFT_H


#include "MatrixActionInterface.h"

class ActionTurnLeft : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONTURNLEFT_H
