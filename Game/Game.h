//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_GAME_H
#define SHOOTER_GAME_H


#include "Matrix2d.h"
#include "Matrix3d.h"
#include "SpaceShip.h"
#include "TargetObject.h"

class Game {

private:
    bool running;
    bool gameLost = false;
    bool gameWon = false;
    SpaceShip spaceShip;
    TargetObject targetObject;

public:
    static std::vector<Matrix3d> cubes;
    Game();

    void Start();

    void HandleInput(float elapsedTime, SDL_Event &event);

    void Draw();

    void Update(float elapsedTime, SDL_Event &event);
};


#endif //SHOOTER_GAME_H
