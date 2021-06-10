//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "SpaceShip.h"
#include "../Engine/headers/MatrixFactory.h"
#include "SpaceShipStates/headers/SpaceShipIdleState.h"


SpaceShip::SpaceShip() : SpaceShip({{1.5, 0, 1},}) {
    Matrix3d m = MatrixFactory::GetShipMatrix(1, 2, 1);
    this->data = m.data;
    this->setOrientationMatrix(m.getOrientationMatrix());
    bullet = Bullet();
    stateMachine = std::make_unique<StateMachine<SpaceShip>>(*this);
    stateMachine->changeGlobalState(new SpaceShipIdleState());
    this->colColor = {255,0,0};
    this->changeColorOnCollision = true;
    this->isBindRandom = true;
}

SpaceShip::SpaceShip(const vector<Point3d> &points) : Matrix3d(points), Cube(3), trace(3) {
    Cube = MatrixFactory::GetCubeMatrix(1, 1, 1);
    trace = Matrix3d({this->getCenterPoint()});
    this->colColor = {255,0,0};
    this->changeColorOnCollision = true;
    this->isBindRandom = true;
}


void SpaceShip::Shoot() {
    auto bul = Bullet();
    bul.data = bullet.data;
    Point3d diff = this->GetTopPoint() - bullet.getCenterPoint();
    bullet.translateMatrixXYZ(diff.x, diff.y, diff.z);
    drawables.emplace_back(bullet);
}

Point3d SpaceShip::GetTopPoint() {
    return Point3d(this->data[0][0], this->data[1][0], this->data[2][0]);
}

Point3d SpaceShip::GetLeftPoint() {
    return Point3d(this->data[0][2], this->data[1][2], this->data[2][2]);
}

void SpaceShip::Draw() {
    if(helpline)
        shootLine.Draw();
    for (auto &obj : drawables) {
        obj.Draw();
    }
    drawTrace();
    Matrix3d::Draw();
}


void SpaceShip::Update(float elapsedTime) {
    this->stateMachine->update(elapsedTime);
    this->updateShootLine();
    for (auto &obj : drawables) {
        obj.updatePosition(elapsedTime);
    }
    if (RenderManager::GetCamera().follow) {
        RenderManager::GetCamera().lookAt.x = this->getCenterPoint().x - 6;
        RenderManager::GetCamera().lookAt.y = this->getCenterPoint().y + 8;

//<<<<<<< HEAD
//    RenderManager::GetCamera().lookAt.x = this->getCenterPoint().x - 4;
//    RenderManager::GetCamera().lookAt.y = this->getCenterPoint().y + 5;
//
//    RenderManager::GetCamera().eye.x = this->getCenterPoint().x + 20;
//    RenderManager::GetCamera().eye.y = this->getCenterPoint().y - 20;
//=======
        RenderManager::GetCamera().eye.x = this->getCenterPoint().x + 20;
        RenderManager::GetCamera().eye.y = this->getCenterPoint().y - 20;
    }
//>>>>>>> ee4888aedaf74d058f08eba41b1951d2886cfa77

}

vector<Bullet> &SpaceShip::getDrawables() {
    return drawables;
}

StateMachine<SpaceShip> &SpaceShip::getStateMachine() const {
    return *this->stateMachine;
}

void SpaceShip::IncreaseMoveSpeed(float by) {
    this->moveSpeed += by;
}

void SpaceShip::DecreaseMoveSpeed(float by) {
    this->moveSpeed -= by;

    if (this->moveSpeed < 0) {
        this->moveSpeed = 0;
    }
}

float SpaceShip::GetMoveSpeed() const {
    return this->moveSpeed;
}

void SpaceShip::addTrace() {
    Point3d p = this->getCenterPoint();
    this->trace.addPoint(p);
}

void SpaceShip::drawTrace() {
    if(RenderManager::DrawDebug) {
        this->trace.Draw();
    }
}

Matrix SpaceShip::rotateMatrixCenter(float degrees, Point3d rotateTowards) {
    Matrix m = Matrix3d::rotateMatrixCenter(degrees, rotateTowards);
    bullet.rotateMatrixCenter(degrees, rotateTowards);
    updateShootLine();
    return m;
}

Matrix SpaceShip::translateMatrixXYZ(float translateX, float translateY, float translateZ) {
    Matrix m = Matrix3d::translateMatrixXYZ(translateX, translateY, translateZ);
    bullet.translateMatrixXYZ(translateX, translateY, translateZ);
    this->updateShootLine();
    updateShootLine();
    return m;
}

void SpaceShip::updateShootLine() {
    //Point3d diff = this->GetTopPoint() - this->getCenterPoint();
    Point3d diff = bullet.GetTopPoint() - bullet.getCenterPoint();
    Point3d norm = diff.getNormalized();
    std::vector<Point3d> shootingPoints;
    shootingPoints.emplace_back(this->GetTopPoint());
    for(int i = 1; i < 20; i++){
        shootingPoints.emplace_back(this->GetTopPoint()+norm*i);
    }
    shootLine = Matrix3d(shootingPoints);
    shootLine.changeColorOnCollision = true;
    shootLine.rgb = {255,0,0};
}

void SpaceShip::SwitchHelpLine() {
    helpline = !helpline;
}

Matrix3d &SpaceShip::getShootLine() {
    return shootLine;
}
