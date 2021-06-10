//
// Created by Ahmad Rahimi on 2/23/18.
//

#include "../headers/ActionRoll.h"

void ActionRoll::handle(SpaceShip &object) {
    auto x = 0;
    auto y = 0;
    auto z = 1;

    object.rotateMatrixCenter(5, Point3d(x, y, z));
}

std::string ActionRoll::getName() {
    return "roll";
}
