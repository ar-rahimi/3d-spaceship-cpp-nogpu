//
// Created by Ahmad Rahimi on 2/27/18.
//

#include "ActionSwitchDebug.h"

void ActionSwitchDebug::handle(SpaceShip &object) {
    RenderManager::DrawDebug = !RenderManager::DrawDebug;
}

std::string ActionSwitchDebug::getName() {
    return std::string();
}
