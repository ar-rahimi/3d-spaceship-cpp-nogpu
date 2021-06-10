//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "../headers/ActionShoot.h"

void ActionShoot::handle(SpaceShip &object) {
    object.Shoot();
}

std::string ActionShoot::getName() {
    return "shoot";
}
