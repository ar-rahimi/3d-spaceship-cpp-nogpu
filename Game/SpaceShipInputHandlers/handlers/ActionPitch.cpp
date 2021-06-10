//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionPitch.h"

void ActionPitch::handle(SpaceShip &object) {
    auto x = 1;
    auto y = 0;
    auto z = 0;

    object.rotateMatrixCenter(5, Point3d(x, y, z));
}

std::string ActionPitch::getName() {
    return "pitch";
}
