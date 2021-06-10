//
// Created by Mevlüt Özdemir on 23-02-18.
//

#ifndef SHOOTER_BULLET_H
#define SHOOTER_BULLET_H


#include "Matrix3d.h"

class Bullet : public Matrix3d{
public:
    bool isSeeking = false; //heatseeking misslesd
    std::string state = "shooting";
    float maxLifeTime = 3000;
    float explodeTime = 400;
    Bullet();

    explicit Bullet(const vector<Point3d> &points);

    Point3d GetTopPoint() override;

    void updatePosition(float elapsedTime);

    void explode(float elapsedTime);
    void Draw();

    float RandomNumber(float Min, float Max)
    {
        return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
    }
};


#endif //SHOOTER_BULLET_H
