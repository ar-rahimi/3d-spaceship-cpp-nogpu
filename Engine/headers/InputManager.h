//
// Created by Mevlüt Özdemir on 09-11-17.
//

#ifndef SHOOTER_INPUTMANAGER_H
#define SHOOTER_INPUTMANAGER_H


#include <SDL_events.h>
#include <map>
#include "Controls.h"

class InputManager {

/**
 * Singleton
 */

private:
    static InputManager *sInstance;

    std::map<SDL_Keycode, Controls> keyDirections;

    InputManager();

public:

    static InputManager *Instance();

    bool hasEvent(SDL_Event *event);

    bool isKeyDown(SDL_Event &event);

    Controls getDirection(SDL_Event &event);
};


#endif //SHOOTER_INPUTMANAGER_H
