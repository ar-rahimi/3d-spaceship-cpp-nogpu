//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_ACTIONHANDLERFACTORY_H
#define SHOOTER_ACTIONHANDLERFACTORY_H


#include "headers/ActionTurnUp.h"

class ActionHandlerFactory {

private:
    MatrixActionInterface *nextHandler;

    std::map<Controls, MatrixActionInterface *> handlers;

    static ActionHandlerFactory *sInstance;

    ActionHandlerFactory();

public:
    static ActionHandlerFactory *Instance();

    MatrixActionInterface *GetAction(Controls direction);
};


#endif //SHOOTER_ACTIONHANDLERFACTORY_H
