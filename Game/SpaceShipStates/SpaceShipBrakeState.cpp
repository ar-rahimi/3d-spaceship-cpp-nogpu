//
// Created by Mevlüt Özdemir on 25-02-18.
//


#include "../SpaceShip.h"
#include "headers/SpaceShipIdleState.h"
#include "headers/SpaceShipBrakeState.h"

void SpaceShipBrakeState::enterState(SpaceShip &owner) {
}

void SpaceShipBrakeState::exitState(SpaceShip &owner) {

}

void SpaceShipBrakeState::updateState(SpaceShip &owner, float elapsedTime) {
    auto speed = owner.GetMoveSpeed();

    if (speed >= 0) {
        Point3d targetPoint = (owner.GetTopPoint() - owner.getCenterPoint()) * speed * elapsedTime / 50;
        owner.translateMatrixXYZ(targetPoint.x, targetPoint.y, targetPoint.z);
        owner.addTrace();
    } else {
        owner.getStateMachine().changeCurrentState(new SpaceShipIdleState());
    }

}

std::string SpaceShipBrakeState::getName() const {
    return "brake-state";
}