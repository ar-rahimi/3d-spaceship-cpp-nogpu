//
// Created by Ahmad Rahimi on 1/31/18.
//

#ifndef SHOOTER_MATRIX_H
#define SHOOTER_MATRIX_H

#include <vector>
#include "point.h"
#include "point3d.h"

class Matrix {
public:
    Matrix(int rows, int cols);
    Matrix(std::vector<std::vector<float>> data);
    std::vector<std::vector<float>> data;
    void insertNumber(float number, int row, int col);
    Matrix operator*(const Matrix& other);

    int getRows() const;
    int getColumns() const;

    void generateMatrixBySize(int rows, int cols);

    Matrix scaleMatrixBy(float scaleBy);
    Matrix identicalMatrix();
    Matrix getIdentityMatrix();
    Matrix nullifyMatrix();
    Matrix translateMatrix(float translateBy);
    void fillMatrix(std::vector<std::vector<float>> fillWith);
    void fillAsTranslateMatrix(std::vector<std::vector<float>> fillWith);
    void logMatrix();
    Matrix reverseMatrixHorizontal();
    std::vector<float> getColumnValues(int col) const;
    std::vector<float> getRowValues(int row) const;
    Matrix getMatrixWithExtraRows(std::vector<std::vector<float>> rowToAdd);

    Point3d get3dVectoAtCol(int col);
    void doCalc();
};

#endif //SHOOTER_MATRIX_H
