//
// Created by Ahmad Rahimi on 2/19/18.
//

#include "Matrix2d.h"

Matrix2d::Matrix2d(int cols) : Matrix(2, cols) {

}

Matrix2d::Matrix2d(std::vector<Vector> coordinates) : Matrix(2, coordinates.size()*2) {
    std::vector<Point> points;

    for(auto &coordinate : coordinates){
        points.emplace_back(coordinate.getBeginPoint());
        points.emplace_back(coordinate.calcEndX(), coordinate.calcEndY());
    }

    fillMatrixWithPoints(points);
}

Matrix2d::Matrix2d(std::vector<Point> points) : Matrix(2, points.size()) {
    fillMatrixWithPoints(points);
}

void Matrix2d::fillMatrixWithPoints(std::vector<Point> points) {
    std::vector<float> x_row;
    std::vector<float> y_row;

    for(auto &point : points){
        x_row.emplace_back(point.x);
        y_row.emplace_back(point.y); //change starting point to 0 with 640 - fmod(point.y,641), but it destroy scaling function
    }

    this->fillMatrix({x_row, y_row});
}

void Matrix2d::Draw() {
    SDL_SetRenderDrawColor(RenderManager::Instance()->GetRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);
    int col = 0;
    while(col+1 < this->data[0].size()){
        Point p1 = Point(this->data[0][col],this->data[1][col]);
        Point p2 = Point(this->data[0][col+1], this->data[1][col+1]);
//        p1.drawToPoint(p2);
        std::cout << "commented out in matrix2d::draw()" << std::endl;
        col++;
    }
}

Matrix Matrix2d::scaleMatrixXY(float scaleX, float scaleY) {
    Matrix m = getScalingMatrix(scaleX, scaleY);
    Matrix result = m**this;
    this->data = result.data;
    return *this;
}

Matrix Matrix2d::translateMatrixXY(float translateX, float translateY) {
    Matrix m = getTranslationMatrixXY(translateX, translateY);
    int col = 0;
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

Matrix Matrix2d::rotateMatrixOrigin(float degrees) {
    Matrix rotationMatrix = getRotationMatrix(degrees);
    Matrix result = rotationMatrix**this;
    this->data = result.data;
    return *this;
}



Matrix Matrix2d::rotateMatrixCenter(float degrees) {
    Point p = getCenterPoint();
//    Matrix translateOriginMatrix = getTranslationMatrixXY(-p.x, -p.y);
//    Matrix translateCenterPointMatrix = getTranslationMatrixXY(p.x, p.y);
//    Matrix rotationMatrix = getRotationMatrix(degrees);
    this->translateMatrixXY(-p.x, -p.y);
    this->rotateMatrixOrigin(degrees);
    this->translateMatrixXY(p.x,p.y);
    return *this;
}

Matrix Matrix2d::getTranslationMatrixXY(float translateX, float translateY) {
    Matrix m = Matrix(this->getRows()+1, this->getRows()+1);

    //m.fillAsTranslateMatrix(this->getIdentityMatrix().data);
    int row = 0;
    bool isX = true;
    while(row < m.getRows()){
        m.data[row][m.getColumns()-1] = isX ? translateX : translateY;
        isX = !isX;
        row++;
    };

    int col = 0;
    while(col < m.getColumns()){
        m.data[col][col] = 1;
        col++;
    };
    return m;
}

Matrix Matrix2d::getScalingMatrix(float scaleX, float scaleY) {
    Matrix m = Matrix(2, 2);
    int col = 0;
    bool isX = true;
    while(col < m.getRows()){
        m.data[col][col] = isX ? scaleX : scaleY;
        isX = !isX;
        col++;
    };
    return m;
}

Matrix Matrix2d::getRotationMatrix(float degrees) {
    Matrix rotationMatrix = Matrix(2,2);
    double radians = degrees * M_PI_2 / 180;
    rotationMatrix.data[0][0] = cosl(radians);
    rotationMatrix.data[0][1] = sinl(radians);
    rotationMatrix.data[1][0] = -(sinl(radians));
    rotationMatrix.data[1][1] = cosl(radians);
    return rotationMatrix;
}

Point Matrix2d::getCenterPoint() {
    float centerX = 0;
    float centerY = 0;

    for(int col = 0; col < this->getColumns(); col++){
        centerX += this->data[0][col];
        centerY += this->data[1][col];
    }

    centerX /= this->getColumns();
    centerY /= this->getColumns();
    return Point(centerX, centerY);
}