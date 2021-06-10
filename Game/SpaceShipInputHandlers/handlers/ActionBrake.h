//
// Created by Mevlüt Özdemir on 25-02-18.
//

#ifndef SHOOTER_ACTIONBRAKE_H
#define SHOOTER_ACTIONBRAKE_H


#include "MatrixActionInterface.h"

class ActionBrake : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;

    bool InBreakState(SpaceShip &object) const;
};


#endif //SHOOTER_ACTIONBRAKE_H
