//
// Created by Ahmad Rahimi on 2/26/18.
//

#include "ActionSwitchHelpLine.h"
void ActionSwitchHelpLine::handle(SpaceShip &object) {
    object.SwitchHelpLine();
}

std::string ActionSwitchHelpLine::getName() {
    return "switch-help-line";
}
