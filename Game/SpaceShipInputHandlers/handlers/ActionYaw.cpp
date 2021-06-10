//
// Created by Ahmad Rahimi on 2/23/18.
//

#include "../headers/ActionYaw.h"

void ActionYaw::handle(SpaceShip &object) {
    auto x = 0;
    auto y = 1;
    auto z = 0;

    object.rotateMatrixCenter(5, Point3d(x, y, z));
}

std::string ActionYaw::getName() {
    return "yaw";
}
