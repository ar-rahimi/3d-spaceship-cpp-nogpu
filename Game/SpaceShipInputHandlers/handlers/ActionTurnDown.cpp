//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionTurnDown.h"


void ActionTurnDown::handle(SpaceShip &object) {
    Point3d target = object.getZAxis();
    object.rotateMatrixCenter(10, target);
}

std::string ActionTurnDown::getName() {
    return "move-bottom";
}
