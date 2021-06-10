//
// Created by Ahmad Rahimi on 2/27/18.
//

#ifndef SHOOTER_ACTIONSWITCHDEBUG_H
#define SHOOTER_ACTIONSWITCHDEBUG_H


#include "MatrixActionInterface.h"

class ActionSwitchDebug : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;
    std::string getName() override;
};


#endif //SHOOTER_ACTIONSWITCHDEBUG_H
