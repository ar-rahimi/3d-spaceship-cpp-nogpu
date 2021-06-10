//
// Created by Ahmad Rahimi on 2/25/18.
//

#include "ActionTurnLeft.h"

void ActionTurnLeft::handle(SpaceShip &object) {
    Point3d target = object.getXAxis();
    object.rotateMatrixCenter(-10, target);
}

std::string ActionTurnLeft::getName() {
    return "turn_left";
}
