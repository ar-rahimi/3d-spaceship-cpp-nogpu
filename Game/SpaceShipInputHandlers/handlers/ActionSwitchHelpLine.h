//
// Created by Ahmad Rahimi on 2/26/18.
//

#ifndef SHOOTER_ACTIONSWITCHHELPLINE_H
#define SHOOTER_ACTIONSWITCHHELPLINE_H


#include <string>
#include "../../SpaceShip.h"
#include "MatrixActionInterface.h"

class ActionSwitchHelpLine : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;
    std::string getName() override;
};


#endif //SHOOTER_ACTIONSWITCHHELPLINE_H
