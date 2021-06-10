//
// Created by Ahmad Rahimi on 1/31/18.
//

#include <iostream>
#include "matrix.h"

void Matrix::insertNumber(float number, int row, int col) {
    this->data[row][col] = number;
}

Matrix Matrix::operator*(const Matrix &other) {
    Matrix result = Matrix(this->getRows(), other.getColumns());
    if(this->getColumns() == other.getRows()) {
        //vermenigvuldig iedere rij van a met iedere kolom van b
        for (int row = 0; row < this->getRows(); row++) {
            for (int col = 0; col < other.getColumns(); col++) {
                std::vector<float> multiplyMatrixRow = this->getRowValues(row);
                std::vector<float> multiplierMatrixColumn = other.getColumnValues(col);
                float newValue = 0;
                for (int i = 0; i < multiplyMatrixRow.size(); i++) {
                    newValue += multiplierMatrixColumn[i]*multiplyMatrixRow[i];
                }
                result.data[row][col] = newValue;
            }
        }
    }
    this->data = result.data;
    return *this;
}

int Matrix::getRows() const  {
    return this->data.size();
}

int Matrix::getColumns()const  {
    return this->data[0].size();
}

void Matrix::generateMatrixBySize(int rows, int cols) {
    int currentRow = 0;
    while(currentRow < rows) {
        std::vector<float> row = std::vector<float>();
        int currentColumn = 0;
        while(currentColumn < cols) {
            row.push_back(0);
            currentColumn++;
        }
        this->data.push_back(row);
        currentRow++;
    }
}

void Matrix::logMatrix() {
    for(auto &row : this->data){
        std::cout << "[ ";
        for(auto &rowValue : row){
            std::cout << rowValue << "|";
        }
        std::cout << " ]" <<std::endl;
    }
}

Matrix::Matrix(int rows, int cols) {
    this->generateMatrixBySize(rows,cols);
}

std::vector<float> Matrix::getColumnValues(int col) const{
    std::vector<float> result;
    if(col < this->getColumns()){
        int row = 0;
        while(row < this->getRows()){
            result.push_back(this->data[row][col]);
            row++;
        }
    }
    return result;
}

std::vector<float> Matrix::getRowValues(int row) const{
    std::vector<float> result;
    if(row < this->getRows()){
        int col = 0;
        while(col < this->getColumns()){
            result.push_back(this->data[row][col]);
            col++;
        }
    }
    return result;
}

Matrix Matrix::scaleMatrixBy(float scaleBy) {
    Matrix m = Matrix(this->getColumns(), this->getColumns());
    int col = 0;
    while(col < m.getRows()){
        m.data[col][col] = scaleBy;
        col++;
    };
    return (*this*m);
}

Matrix Matrix::identicalMatrix() {
    return this->scaleMatrixBy(1);
}

Matrix Matrix::nullifyMatrix() {
    return this->scaleMatrixBy(0);
}

Matrix Matrix::translateMatrix(float translateBy) {
    Matrix m = Matrix(this->getRows()+1, this->getRows()+1);

    //m.fillAsTranslateMatrix(this->getIdentityMatrix().data);
    int row = 0;
    while(row < m.getRows()){
        m.data[row][m.getColumns()-1] = translateBy;
        row++;
    };

    int col = 0;
    while(col < m.getColumns()){
        m.data[col][col] = 1;
        col++;
    };
    col = 0;
    std::vector<float> helpRow;
    while(col < this->getColumns()){
        helpRow.emplace_back(1);
        col++;
    };

    this->data.emplace_back(helpRow);
    this->data = (m**this).data;
    this->data.erase(this->data.begin() + this->data.size()-1);
    return *this;
}

void Matrix::fillMatrix(std::vector<std::vector<float>> fillWith) {
    int currentRow = 0;
    while (currentRow < fillWith.size()) {
        std::vector<float> row = std::vector<float>();
        int currentColumn = 0;
        while (currentColumn < this->getColumns()) {
            row.push_back(fillWith[currentRow][currentColumn]);
            currentColumn++;
        }
        this->data[currentRow] = row;
        currentRow++;
    }
}

void Matrix::fillAsTranslateMatrix(std::vector<std::vector<float>> fillWith){
    int currentRow = 0;
    while(currentRow < fillWith.size()) {
        int currentColumn = 0;
        while(currentColumn < this->getColumns()) {
            this->data[currentRow][currentColumn] = fillWith[currentRow][currentColumn];
            currentColumn++;
        }
        currentRow++;
    }
    int lastRowCol = 0;
    while(lastRowCol < this->getColumns()){
        this->data[currentRow][lastRowCol] = 1;
        lastRowCol++;
    }
}

Matrix Matrix::getIdentityMatrix() {
    Matrix m = Matrix(this->getColumns(), this->getColumns());
    int col = 0;
    while(col < m.getRows()){
        m.data[col][col] = 1;
        col++;
    };
    return m;
}

Matrix Matrix::getMatrixWithExtraRows(std::vector<std::vector<float>> rowToAdd) {
    Matrix modifyMatrix = Matrix(0,0);
    modifyMatrix.data = this->data;
    modifyMatrix.data.insert(modifyMatrix.data.end(), rowToAdd.begin(), rowToAdd.end());
    return modifyMatrix;
}

Point3d Matrix::get3dVectoAtCol(int col) {
    if(this->getRows() < 3){
        return Point3d(0,0,0);
    }
    return Point3d(this->data[0][0], this->data[1][col], this->data[2][col]);
}

Matrix::Matrix(std::vector<std::vector<float>> fillWith) {
    this->data = fillWith;
}

Matrix Matrix::reverseMatrixHorizontal() {
    return Matrix({{data[0][0], data[1][0], data[2][0]}});
}

void Matrix::doCalc() {

}
