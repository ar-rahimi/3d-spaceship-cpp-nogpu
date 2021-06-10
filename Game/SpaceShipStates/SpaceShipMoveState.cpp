//
// Created by Mevlüt Özdemir on 25-02-18.
//

#include "./headers/SpaceShipMoveState.h"
#include "../SpaceShip.h"

void SpaceShipMoveState::enterState(SpaceShip &owner) {
}

void SpaceShipMoveState::exitState(SpaceShip &owner) {
    std:cout << "exit ship move state" << std::endl;
}

void SpaceShipMoveState::updateState(SpaceShip &owner, float elapsedTime) {
    auto speed = owner.GetMoveSpeed();
    if (speed > 0) {
        Point3d top = owner.GetTopPoint();
        Point3d center = owner.getCenterPoint();
        Point3d target = (owner.GetTopPoint() - owner.getCenterPoint()) * speed * elapsedTime / 50;
        owner.translateMatrixXYZ(target.x, target.y, target.z);
        owner.addTrace();
    }

}

std::string SpaceShipMoveState::getName() const {
    return "move-state";
}
