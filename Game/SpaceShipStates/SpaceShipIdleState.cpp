//
// Created by Mevlüt Özdemir on 25-02-18.
//

#include "./headers/SpaceShipIdleState.h"
#include "../SpaceShip.h"

void SpaceShipIdleState::enterState(SpaceShip &owner) {

}

void SpaceShipIdleState::exitState(SpaceShip &owner) {

}

void SpaceShipIdleState::updateState(SpaceShip &owner, float elapsedTime) {

}

std::string SpaceShipIdleState::getName() const {
    return "idle";
}
