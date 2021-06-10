//
// Created by Ahmad Rahimi on 2/25/18.
//

#include "ActionGas.h"
#include "../../SpaceShipStates/headers/SpaceShipMoveState.h"


string ActionGas::getName() {
    return "action-gas";
}

void ActionGas::handle(SpaceShip &object) {
    object.IncreaseMoveSpeed();

    if (!this->InMoveState(object)) {
        object.getStateMachine().changeCurrentState(new SpaceShipMoveState());
    }
}

bool ActionGas::InMoveState(SpaceShip &object) const {
    return object.getStateMachine().getCurrentState()->getName() == "move-state";
}
