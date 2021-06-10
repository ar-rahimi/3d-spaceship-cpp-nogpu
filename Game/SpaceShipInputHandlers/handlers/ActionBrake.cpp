//
// Created by Mevlüt Özdemir on 25-02-18.
//

#include "ActionBrake.h"
#include "../../SpaceShipStates/headers/SpaceShipBrakeState.h"


void ActionBrake::handle(SpaceShip &object) {

    object.DecreaseMoveSpeed();

    if (!InBreakState(object)) {
        object.getStateMachine().changeCurrentState(new SpaceShipBrakeState());
    }
}

bool ActionBrake::InBreakState(SpaceShip &object) const {
    object.getStateMachine().getCurrentState()->getName() == "brake-state";
}

std::string ActionBrake::getName() {
    return "brake";
}


