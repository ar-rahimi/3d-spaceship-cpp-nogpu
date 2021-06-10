//
// Created by Ahmad Rahimi on 2/23/18.
//

#ifndef SHOOTER_ACTIONYAW_H
#define SHOOTER_ACTIONYAW_H


#include "../handlers/MatrixActionInterface.h"

class ActionYaw : public MatrixActionInterface {

public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};


#endif //SHOOTER_ACTIONYAW_H
