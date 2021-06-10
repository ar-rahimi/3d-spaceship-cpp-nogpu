//
// Created by Ahmad Rahimi on 2/25/18.
//

#include "ActionTurnRight.h"

void ActionTurnRight::handle(SpaceShip &object) {
    Point3d target = object.getXAxis();
    object.rotateMatrixCenter(10, target);
}

std::string ActionTurnRight::getName() {
    return "turn_right";
}
