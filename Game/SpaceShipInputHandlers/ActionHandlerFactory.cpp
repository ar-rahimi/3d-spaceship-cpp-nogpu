//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "ActionHandlerFactory.h"
#include "headers/ActionNull.h"
#include "headers/ActionTurnDown.h"
#include "headers/ActionMoveLeft.h"
#include "headers/ActionMoveRight.h"
#include "headers/ActionScaleUp.h"
#include "headers/ActionScaleDown.h"
#include "headers/ActionPitch.h"
#include "headers/ActionShoot.h"
#include "headers/ActionYaw.h"
#include "headers/ActionRoll.h"
#include "handlers/ActionRollLeft.h"
#include "handlers/ActionRollRight.h"
#include "handlers/ActionTurnLeft.h"
#include "handlers/ActionTurnRight.h"
#include "handlers/ActionGas.h"
#include "handlers/ActionBrake.h"
#include "handlers/ActionSwitchHelpLine.h"
#include "handlers/ActionSwitchDebug.h"
ActionHandlerFactory *ActionHandlerFactory::sInstance = nullptr;

ActionHandlerFactory::ActionHandlerFactory() {
    handlers = {
            {Controls::Top,             new ActionTurnUp()},
            {Controls::Bottom,          new ActionTurnDown()},
            {Controls::ScaleUp,         new ActionScaleUp()},
            {Controls::ScaleDown,       new ActionScaleDown()},
            {Controls::Pitch,           new ActionPitch()},
            {Controls::Yaw,             new ActionYaw()},
            {Controls::Roll,            new ActionRoll()},
            {Controls::RollLeft,        new ActionRollLeft()},
            {Controls::RollRight,       new ActionRollRight()},
            {Controls::TurnLeft,        new ActionTurnLeft()},
            {Controls::TurnRight,       new ActionTurnRight()},
            {Controls::Gas,             new ActionGas()},
            {Controls::Brake,           new ActionBrake()},
            {Controls::Space,           new ActionShoot()},
            {Controls::SwitchHelpLine,  new ActionSwitchHelpLine()},
            {Controls::SwitchDebug,     new ActionSwitchDebug()}
    };
}

ActionHandlerFactory *ActionHandlerFactory::Instance() {
    if (sInstance == nullptr) {
        sInstance = new ActionHandlerFactory();
    }

    return sInstance;
}


MatrixActionInterface *ActionHandlerFactory::GetAction(Controls direction) {
    auto it = handlers.find(direction);

    if (it != handlers.end()) {
        return it->second;
    }

    return new ActionNull();
}
