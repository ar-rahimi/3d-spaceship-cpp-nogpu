//
// Created by Mevlüt Özdemir on 25-02-18.
//

#ifndef SHOOTER_SPACESHIPMOVESTATE_H
#define SHOOTER_SPACESHIPMOVESTATE_H


#include "../../SpaceShip.h"

class SpaceShipMoveState : public State<SpaceShip> {

public:
    void enterState(SpaceShip &owner) override;

    void exitState(SpaceShip &owner) override;

    void updateState(SpaceShip &owner, float elapsedTime) override;

    std::string getName() const override;
};

#endif //SHOOTER_SPACESHIPMOVESTATE_H
