//
// Created by Ahmad Rahimi on 2/25/18.
//

#ifndef SHOOTER_ACTIONGAS_H
#define SHOOTER_ACTIONGAS_H


#include "../../SpaceShip.h"
#include "MatrixActionInterface.h"

class ActionGas : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;

    bool InMoveState(SpaceShip &object) const;
};


#endif //SHOOTER_ACTIONGAS_H
