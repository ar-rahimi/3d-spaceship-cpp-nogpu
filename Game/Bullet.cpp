//
// Created by Mevlüt Özdemir on 23-02-18.
//

#include "Bullet.h"
#include "../Engine/headers/MatrixFactory.h"

Bullet::Bullet() : Bullet({{1.5, 0, 1},}) {
    this->data = MatrixFactory::GetBulletMatrix(0.3, 0.3, 0.3).data;
}

Bullet::Bullet(const vector<Point3d> &points) : Matrix3d(points) {}

Point3d Bullet::GetTopPoint() {
    return Point3d(this->data[0][17], this->data[1][17], this->data[2][17]);
}

void Bullet::updatePosition(float elapsedTime) {
    if(isVisible) {
        if (state == "shooting") {
            maxLifeTime -= elapsedTime;
            if (maxLifeTime < 0)
                state = "exploding";
            if(!isSeeking) {
                Point3d top = this->GetTopPoint();
                Point3d center = this->getCenterPoint();
                Point3d target = (top - center) / 2 * (elapsedTime / 50);
                this->translateMatrixXYZ(target.x, target.y, target.z);
                this->rotateMatrixCenter(5 * (elapsedTime / 10), target);
            }else{

            }

        } else if (state == "exploding") {
            isBindRandom = true;
            this->explode(elapsedTime);
        }
    }
}

void Bullet::Draw() {
    if(isVisible)
        Matrix3d::Draw();
}

void Bullet::explode(float elapsedTime) {
    if (explodeTime < 0) {
        state = "destroyed";
        isVisible = false;
    }else{
        this->rgb = {this->RandomNumber(0,255),this->RandomNumber(0,255),this->RandomNumber(0,255)};
        explodeTime -= elapsedTime;
        std::vector<std::vector<float>> addExplosion = {{},{},{}};
        for(int i = 0; i < this->data[0].size(); i++){
            float _x = this->data[0][i] + this->RandomNumber(-0.3, 0.3);
            float _y = this->data[1][i] + this->RandomNumber(-0.3, 0.3);
            float _z = this->data[2][i] + this->RandomNumber(-0.3, 0.3);
            this->data[0][i] = _x;
            this->data[1][i] = _y;
            this->data[2][i] = _z;
            if(this->RandomNumber(0,255) < 150) {
            addExplosion[0].emplace_back(_x);
            addExplosion[1].emplace_back(_y);
            addExplosion[2].emplace_back(_z);
            }
        }

            this->data[0].insert(this->data[0].end(), addExplosion[0].begin(), addExplosion[0].end());
            this->data[1].insert(this->data[1].end(), addExplosion[1].begin(), addExplosion[1].end());
            this->data[2].insert(this->data[2].end(), addExplosion[2].begin(), addExplosion[2].end());

    }
}

