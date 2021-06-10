//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionScaleUp.h"

void ActionScaleUp::handle(SpaceShip &object) {
    object.scaleMatrixXYZ(1.01, 1.01, 1.01);
}

std::string ActionScaleUp::getName() {
    return "scale-up";
}
