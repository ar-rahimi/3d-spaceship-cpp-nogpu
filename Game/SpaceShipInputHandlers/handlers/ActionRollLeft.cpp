//
// Created by Ahmad Rahimi on 2/25/18.
//

#include "ActionRollLeft.h"

void ActionRollLeft::handle(SpaceShip &object) {
    Point3d target = object.getYAxis() / 2;
    object.rotateMatrixCenter(20, target);
}

std::string ActionRollLeft::getName() {
    return "roll_left";
}
