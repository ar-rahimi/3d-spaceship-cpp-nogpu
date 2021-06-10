//
// Created by Ahmad Rahimi on 2/25/18.
//

#ifndef SHOOTER_ACTIONROLLLEFT_H
#define SHOOTER_ACTIONROLLLEFT_H


#include "MatrixActionInterface.h"

class ActionRollLeft : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};

#endif //SHOOTER_ACTIONROLLLEFT_H
