//
// Created by Ahmad Rahimi on 2/21/18.
//

#ifndef SHOOTER_MATRIX3D_H
#define SHOOTER_MATRIX3D_H


#include "matrix.h"
#include "mvector.h"
#include "point3d.h"
#include "../Engine/headers/Drawable.h"

class Matrix3d : public Matrix, public Drawable {
public:
    bool changeColorOnCollision = false;
    std::vector<int> colColor = {0,255,0};
    bool isOnCollision = false;
    bool isBindRandom = false;
    bool isVisible = true;
    Matrix3d(int cols);

    Matrix3d(std::vector<Point3d> points);

    void Draw() override; // implementation of drawable

    void fillMatrixWithPoints(std::vector<Point3d> points);

    Matrix scaleMatrixXYZ(float scaleX, float scaleY, float scaleZ);

    virtual Matrix translateMatrixXYZ(float translateX, float translateY, float translateZ);
    Matrix scaleMatrixXYZCenter(float scaleX, float scaleY, float scaleZ);
    Matrix rotateMatrixOrigin(float degrees);

    virtual Matrix rotateMatrixCenter(float degrees, Point3d rotateTowards);

    Matrix getTranslationMatrixXYZ(float translateX, float translateY, float translateZ);

    Matrix getScalingMatrixXYZ(float scaleX, float scaleY, float scaleZ);

    Point3d getCenterPoint();

//    Matrix correctViewMatrix(Matrix viewMatrix);

    virtual void Update(float elapsedTime);

    std::vector<int> rgb = {255,255,255};

public:
    virtual Point3d GetTopPoint(){};
    virtual Point3d GetLeftPoint(){};
    void addPoint(Point3d p);

protected:
    bool hasOrientationMatrix = false;
    Matrix3d *orientationMatrix;

public:
    Matrix3d *getOrientationMatrix() const;
public:
    void setOrientationMatrix(Matrix3d *orientationMatrix);

    Point3d getXAxis();
    Point3d getYAxis();
    Point3d getZAxis();
    bool checkCollision(Matrix3d other);
    virtual void isCollided();
    std::vector<Point3d> getCollisionPoints();
    bool doConnect() {
        return 0 + (rand() % (1 - 0 + 1)) == 1;
    }

    void destroy();
private:
    Matrix fixFinalCalculation(Matrix m);
};

#endif //SHOOTER_MATRIX3D_H
