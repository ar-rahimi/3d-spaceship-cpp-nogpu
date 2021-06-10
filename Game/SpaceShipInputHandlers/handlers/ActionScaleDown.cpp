//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionScaleDown.h"

void ActionScaleDown::handle(SpaceShip &object) {
    object.scaleMatrixXYZ(0.99, 0.99, 0.99);
}

std::string ActionScaleDown::getName() {
    return "scale-down";
}
