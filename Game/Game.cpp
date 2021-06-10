//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include <SDL_events.h>
#include <SDL.h>
#include "Game.h"
#include "../Engine/headers/Timer.h"
#include "../Engine/headers/InputManager.h"
#include "SpaceShip.h"
#include "SpaceShipInputHandlers/ActionHandlerFactory.h"
#include "TargetObject.h"
#include "../Engine/headers/MatrixFactory.h"

std::vector<Matrix3d> Game::cubes;
namespace {
    const int FPS = 40;
    const int MAX_FPS = 80;
}

Game::Game() :
        running{true},
        spaceShip{SpaceShip()},
        targetObject{TargetObject()} {

    SDL_Init(SDL_INIT_EVERYTHING);

    // todo: loop
    auto matrix = MatrixFactory::GetCubeMatrix(1, 1, 1);
    matrix.translateMatrixXYZ(10, 10, 0);
    cubes.push_back(matrix);

    matrix = MatrixFactory::GetCubeMatrix(1, 1, 1);
    matrix.translateMatrixXYZ(5, 5, 4);
    cubes.push_back(matrix);

    matrix = MatrixFactory::GetCubeMatrix(1, 1, 1);
    matrix.translateMatrixXYZ(9, 2, 2);
    cubes.push_back(matrix);

    //set beginnen point normale begin
    spaceShip.translateMatrixXYZ(5,5,10);
    spaceShip.rotateMatrixCenter(240, spaceShip.getZAxis());
    spaceShip.rotateMatrixCenter(240, spaceShip.getYAxis());

    //test cube
    Point3d cp = spaceShip.getCenterPoint() - matrix.getCenterPoint();
    matrix = MatrixFactory::GetCubeMatrix(1.5, 1, 1);
    matrix.translateMatrixXYZ(cp.x, cp.y, cp.z);
    cubes.push_back(matrix);
    matrix = MatrixFactory::GetCubeMatrix(1, 1.5, 1);
    matrix.translateMatrixXYZ(cp.x-2, cp.y, cp.z);
    cubes.push_back(matrix);
    matrix = MatrixFactory::GetCubeMatrix(1, 1, 1.5);
    matrix.translateMatrixXYZ(cp.x, cp.y-2, cp.z);
    cubes.push_back(matrix);
    matrix = MatrixFactory::GetCubeMatrix(3, 3, 3);
    matrix.translateMatrixXYZ(cp.x, cp.y, cp.z-2);
    cubes.push_back(matrix);
    targetObject.translateMatrixXYZ(cp.x+2,cp.y,cp.z);
}

void Game::Start() {
    SDL_Event event{};

    Timer timer{FPS, MAX_FPS};

    while (running) {

        SDL_PumpEvents();

        this->Update(timer.getElapsedTime(), event);
        this->Draw();
    }
}

void Game::Update(float elapsedTime, SDL_Event &event) {
    if (SDL_PollEvent(&event)) {
        this->HandleInput(elapsedTime, event);
    }

    spaceShip.Update(elapsedTime);
    targetObject.Update(elapsedTime);
    for(auto &cube : cubes){
        spaceShip.getShootLine().checkCollision(cube);
        for(auto &bullet : spaceShip.getDrawables()){
            if(bullet.checkCollision(cube)){
                cube.destroy();
            };
        }
        if(spaceShip.checkCollision(cube)){
            if(!RenderManager::DrawDebug && !gameLost && !gameWon) {
                gameLost = true;
                std::cout << "Game Over, you collided against a cube!" << std::endl;
                spaceShip.rgb = {255,0,0};
            }else if(!gameLost && !gameWon){
                std::cout << "Training: you collided!" << std::endl;
            }
        }
    }

    for(auto &bullet : spaceShip.getDrawables()){
        if(bullet.checkCollision(targetObject) && !gameLost && !gameWon){
            gameWon = true;
            std::cout << "You won you destroyed the target, you can continue to play!!" << std::endl;
            spaceShip.rgb = {0,255,0};
            targetObject.destroy();
        };
    }
    if(targetObject.checkCollision(spaceShip) && !gameLost && !gameWon){
        if(!RenderManager::DrawDebug) {
            gameLost = true;
            std::cout << "Game Over, you collided against a cube!" << std::endl;
            spaceShip.rgb = {255,0,0};
        }else{
            std::cout << "Training: you collided!" << std::endl;
        }
    }
}

void Game::HandleInput(float elapsedTime, SDL_Event &event) {
    auto inputManager = InputManager::Instance();
    auto actionHandler = ActionHandlerFactory::Instance();
    if (inputManager->isKeyDown(event)) {
        auto direction = inputManager->getDirection(event);
        actionHandler
                ->GetAction(direction)
                ->setElapsedTime(elapsedTime)
                ->handle(spaceShip);
        if(Controls::GiveInfo == direction){
            for(auto &cube : cubes){
                std::cout << Point3d::GetDistance(cube.getCenterPoint(), spaceShip.getCenterPoint()) << std::endl;
            }
        }
        RenderManager::GetCamera().handleEvents(direction);

        RenderManager::Instance()->GetCamera().updatePosition(direction);
    }

}

void Game::Draw() {
    auto renderManager = RenderManager::Instance();
    renderManager->Clear();

    spaceShip.Draw();
    targetObject.Draw();

    for (auto &obj : cubes) {
        obj.Draw();
    }

    renderManager->Flip();
}

