//
// Created by Ahmad Rahimi on 2/19/18.
//

#ifndef SHOOTER_MATRIX2D_H
#define SHOOTER_MATRIX2D_H


#include "matrix.h"
#include "mvector.h"
class Matrix2d : public Matrix {
public:
    Matrix2d(int cols);
    Matrix2d(std::vector<Vector> coordinates);
    Matrix2d(std::vector<Point> points);

    void fillMatrixWithPoints(std::vector<Point> points);

    Matrix scaleMatrixXY(float scaleX, float scaleY);
    Matrix translateMatrixXY(float translateX, float translateY);

    Matrix rotateMatrixOrigin(float degrees);
    Matrix rotateMatrixCenter(float degrees);

    Matrix getTranslationMatrixXY(float translateX, float translateY);
    Matrix getScalingMatrix(float scaleX, float scaleY);
    Matrix getRotationMatrix(float degrees);

    Point getCenterPoint();
    void Draw();
};


#endif //SHOOTER_MATRIX2D_H
