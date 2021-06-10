//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionTurnUp.h"


void ActionTurnUp::handle(SpaceShip &object) {
    Point3d target = object.getZAxis();
    object.rotateMatrixCenter(-10, target);
}

std::string ActionTurnUp::getName() {
    return "move-top";
}
