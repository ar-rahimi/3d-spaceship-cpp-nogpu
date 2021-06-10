//
// Created by Mevlüt Özdemir on 09-11-17.
//

#include <iostream>
#include "headers/InputManager.h"
#include "headers/Controls.h"


InputManager *InputManager::sInstance = 0;

InputManager::InputManager() {
    InputManager::keyDirections = {
            {SDLK_w,     Controls::Top},
            {SDLK_d,     Controls::TurnRight},
            {SDLK_s,     Controls::Bottom},
            {SDLK_a,     Controls::TurnLeft},
            {SDLK_q,     Controls::RollLeft},
            {SDLK_e,     Controls::RollRight},
            {SDLK_f,     Controls::ScaleUp},
            {SDLK_g,     Controls::ScaleDown},
            {SDLK_UP,    Controls::CamUp},
            {SDLK_DOWN,  Controls::CamDown},
            {SDLK_RIGHT, Controls::CamRight},
            {SDLK_LEFT,  Controls::CamLeft},
            {SDLK_0,     Controls::CamScaleUp},
            {SDLK_9,     Controls::CamScaleDown},
            {SDLK_1,     Controls::Pitch},
            {SDLK_2,     Controls::Roll},
            {SDLK_3,     Controls::Yaw},
            {SDLK_SPACE, Controls::Space},
            {SDLK_LSHIFT, Controls::Gas},
            {SDLK_l, Controls::RotateCamRight},
            {SDLK_j, Controls::RotateCamLeft},
            {SDLK_i, Controls::RotateCamUp},
            {SDLK_k, Controls::RotateCamDown},
            {SDLK_z,     Controls::Brake},
            {SDLK_RSHIFT, Controls::SwitchCamera},
            {SDLK_LCTRL, Controls::SwitchDebug},
            {SDLK_y, Controls::SwitchHelpLine},
            {SDLK_b, Controls::GiveInfo}
    };
}

InputManager *InputManager::Instance() {
    if (sInstance == nullptr) {
        sInstance = new InputManager();
    }

    return sInstance;
}

bool InputManager::hasEvent(SDL_Event *event) {
    return static_cast<bool>(SDL_PollEvent(event));
}


bool InputManager::isKeyDown(SDL_Event &event) {
    return event.type == SDL_KEYDOWN;
}

Controls InputManager::getDirection(SDL_Event &event) {
    auto search = keyDirections.find(event.key.keysym.sym);

    if (search != keyDirections.end()) {
        return search->second; // search->first is the key.. search->second is the value..
    }

    // if the key does not exists in the map. It is not a valid key.
    return Controls::Null;
}



