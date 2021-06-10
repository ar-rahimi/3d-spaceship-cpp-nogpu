//
// Created by Ahmad Rahimi on 2/25/18.
//

#ifndef SHOOTER_ACTIONTURNRIGHT_H
#define SHOOTER_ACTIONTURNRIGHT_H


#include "MatrixActionInterface.h"

class ActionTurnRight : public MatrixActionInterface {
public:
    void handle(SpaceShip &object) override;

    std::string getName() override;
};



#endif //SHOOTER_ACTIONTURNRIGHT_H
