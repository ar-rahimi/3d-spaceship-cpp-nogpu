//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionNull.h"

void ActionNull::handle(SpaceShip &object) {
    // do nothing :)
}

std::string ActionNull::getName() {
    return "null";
}
