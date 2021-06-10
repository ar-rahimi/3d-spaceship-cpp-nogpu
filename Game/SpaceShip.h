//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_PLANET_H
#define SHOOTER_PLANET_H


#include "Matrix3d.h"
#include "Bullet.h"
#include "../Engine/StateMachine/StateMachine.h"

class SpaceShip : public Matrix3d {

private:
    std::vector<Bullet> drawables;
    Matrix3d Cube;
    std::unique_ptr<StateMachine<SpaceShip>> stateMachine;
    float moveSpeed = 0.00;
    Matrix3d trace;
    Bullet bullet;
    Matrix3d shootLine = Matrix3d(0);
public:
    Matrix3d &getShootLine();

private:
    bool helpline = true;

public:


    SpaceShip();

    explicit SpaceShip(const vector<Point3d> &points);

    vector<Bullet> &getDrawables();

    StateMachine<SpaceShip> &getStateMachine() const;

    void IncreaseMoveSpeed(float by = 0.01);

    void DecreaseMoveSpeed(float by = 0.01);

    float GetMoveSpeed() const;

    void Shoot();

    void Draw() override;

    void Update(float elapsedTime) override;

    Point3d GetTopPoint();

    Point3d GetLeftPoint();

    void addTrace();

    void drawTrace();

    Matrix translateMatrixXYZ(float translateX, float translateY, float translateZ);

    virtual Matrix rotateMatrixCenter(float degrees, Point3d rotateTowards);

    void updateShootLine();

    void SwitchHelpLine();
};


#endif //SHOOTER_PLANET_H
