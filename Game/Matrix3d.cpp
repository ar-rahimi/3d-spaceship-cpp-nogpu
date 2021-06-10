//
// Created by Ahmad Rahimi on 2/21/18.
//

#include "Matrix3d.h"
#include "../Engine/headers/Helper.h"

Matrix3d::Matrix3d(int cols) : Matrix(3, cols) {

}

Matrix3d::Matrix3d(std::vector<Point3d> points) : Matrix(3, points.size()) {
    fillMatrixWithPoints(points);
}

void Matrix3d::fillMatrixWithPoints(std::vector<Point3d> points) {
    std::vector<float> x_row, y_row, z_row;

    for (auto &point : points) {
        x_row.emplace_back(point.x);
        y_row.emplace_back(point.y);
        z_row.emplace_back(point.z);
    }

    this->fillMatrix({x_row, y_row, z_row});
}

Matrix Matrix3d::scaleMatrixXYZ(float scaleX, float scaleY, float scaleZ) {
    if(hasOrientationMatrix)
        orientationMatrix->scaleMatrixXYZ(scaleX, scaleY, scaleZ);
    Matrix m = getScalingMatrixXYZ(scaleX, scaleY, scaleZ);
    Matrix result = m * *this;
    this->data = result.data;
    return *this;
}

Matrix Matrix3d::scaleMatrixXYZCenter(float scaleX, float scaleY, float scaleZ) {
    Point3d before = Point3d(this->data[0][0],this->data[1][0],this->data[2][0]);
    scaleMatrixXYZ(scaleX,scaleY,scaleZ);
    Point3d result = Point3d(this->data[0][0],this->data[1][0],this->data[2][0]) - before;
    translateMatrixXYZ(-result.x*2, -result.y*2,-result.z*2);
    return *this;
}

Matrix Matrix3d::translateMatrixXYZ(float translateX, float translateY, float translateZ) {
    if(hasOrientationMatrix)
        orientationMatrix->translateMatrixXYZ(translateX, translateY, translateZ);
    Matrix m = getTranslationMatrixXYZ(translateX, translateY, translateZ);
    int col = 0;
    std::vector<float> helpRow;
    while (col < this->getColumns()) {
        helpRow.emplace_back(1);
        col++;
    };

    this->data.emplace_back(helpRow);
    this->data = (m * *this).data;
    this->data.erase(this->data.begin() + this->data.size() - 1);
    return *this;
}

Matrix Matrix3d::getTranslationMatrixXYZ(float translateX, float translateY, float translateZ) {
    Matrix m = Matrix(this->getRows() + 1, this->getRows() + 1);

    //m.fillAsTranslateMatrix(this->getIdentityMatrix().data);
    m.data[0][m.getColumns() - 1] = translateX;
    m.data[1][m.getColumns() - 1] = translateY;
    m.data[2][m.getColumns() - 1] = translateZ;

    int col = 0;
    while (col < m.getColumns()) {
        m.data[col][col] = 1;
        col++;
    };

    return m;
}

Matrix Matrix3d::getScalingMatrixXYZ(float scaleX, float scaleY, float scaleZ) {
    Matrix m = Matrix(3, 3);
    m.data[0][0] = scaleX;
    m.data[1][1] = scaleY;
    m.data[2][2] = scaleZ;
    return m;
}

Point3d Matrix3d::getCenterPoint() {
    float centerX = 0;
    float centerY = 0;
    float centerZ = 0;

    for (int col = 0; col < this->getColumns(); col++) {
        centerX += this->data[0][col];
        centerY += this->data[1][col];
        centerZ += this->data[2][col];
    }

    centerX /= this->getColumns();
    centerY /= this->getColumns();
    centerZ /= this->getColumns();
    return Point3d(centerX, centerY, centerZ);
}


void Matrix3d::Draw() {
    if(!isVisible)
        return;
    if(hasOrientationMatrix && RenderManager::DrawDebug)
        orientationMatrix->Draw();

    Camera c = RenderManager::GetCamera();
    Matrix cViewMatrix = c.correctViewMatrix(*this);
    Matrix mViewMatrix = c.getProjectionMatrix() * c.getCameraMatrix() * cViewMatrix;
    cViewMatrix = fixFinalCalculation(mViewMatrix);
    Point prevPoint = {0, 0};

    bool isBegin = true;
    if(isOnCollision && changeColorOnCollision) {
        SDL_SetRenderDrawColor(RenderManager::Instance()->GetRenderer(), colColor[0], colColor[1], colColor[2], SDL_ALPHA_OPAQUE);
    }else{
        SDL_SetRenderDrawColor(RenderManager::Instance()->GetRenderer(), rgb[0], rgb[1], rgb[2], SDL_ALPHA_OPAQUE);
    }
    for (int col = 0; col < mViewMatrix.getColumns(); col++) {
        Point objectPoint = Point3d(mViewMatrix.data[0][col], mViewMatrix.data[1][col], mViewMatrix.data[2][col]).convertTo2dPoint(200);
        if (isBegin) {
            isBegin = false;
        } else {
            if(!isBindRandom)
                prevPoint.drawTo(objectPoint);
            else{
                if(doConnect()){
                    prevPoint.drawTo(objectPoint);
                }
            }
        }
        prevPoint = objectPoint;
    }
    SDL_SetRenderDrawColor(RenderManager::Instance()->GetRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
    cViewMatrix.doCalc();
}

Matrix Matrix3d::rotateMatrixCenter(float degrees, Point3d rotateTowards) {
    if(hasOrientationMatrix)
        this->orientationMatrix->rotateMatrixCenter(degrees, rotateTowards);
    Point3d p = getCenterPoint();
    Point3d v = rotateTowards;
    if (degrees == 0.f)
        return *this;

    float a = Helper::GetRadians(degrees);
    float t1 = atan2f(v.z, v.x);
    float t2 = atan2f(v.y, sqrtf(v.x * v.x + v.z * v.z));
    //transleren naar origin

    Matrix m0 = Matrix({
                               {1.f, 0.f, 0.f, -rotateTowards.x},
                               {0.f, 1.f, 0.f, -rotateTowards.y},
                               {0.f, 0.f, 1.f, -rotateTowards.z},
                               {0.f, 0.f, 0.f, 1.f}
                       });
    //t1
    Matrix m1 = Matrix({
                               {cos(t1),  0.f, sin(t1), 0.f},
                               {0.f,      1.f, 0.f,     0.f},
                               {-sin(t1), 0.f, cos(t1), 0.f},
                               {0.f,      0.f, 0.f,     1.f}
                       });
    //t2
    Matrix m2 = Matrix({
                               {cos(t2),  sin(t2), 0.f, 0.f},
                               {-sin(t2), cos(t2), 0.f, 0.f},
                               {0.f,      0.f,     1.f, 0.f},
                               {0.f,      0.f,     0.f, 1.f}
                       });
    //roteren over x
    Matrix m3 = Matrix({
                               {1.f, 0.f,    0.f,     0.f},
                               {0.f, cos(a), -sin(a), 0.f},
                               {0.f, sin(a), cos(a),  0.f},
                               {0.f, 0.f,    0.f,     1.f}
                       });
    //-t2
    Matrix m4 = Matrix({
                               {cos(t2), -sin(t2), 0.f, 0.f},
                               {sin(t2), cos(t2),  0.f, 0.f},
                               {0.f,     0.f,      1.f, 0.f},
                               {0.f,     0.f,      0.f, 1.f}
                       });
    //-t1
    Matrix m5 = Matrix({
                               {cos(t1), 0.f, -sin(t1), 0.f},
                               {0.f,     1.f, 0.f,      0.f},
                               {sin(t1), 0.f, cos(t1),  0.f},
                               {0.f,     0.f, 0.f,      1.f}
                       });
    //terug transleren
    Matrix m6 = Matrix({
                               {1.f, 0.f, 0.f, rotateTowards.x},
                               {0.f, 1.f, 0.f, rotateTowards.y},
                               {0.f, 0.f, 1.f, rotateTowards.z},
                               {0.f, 0.f, 0.f, 1.f}
                       });


    Matrix result = /*m6 */ (m5 * (m4 * (m3 * (m2 * (m1 /* m0*/)))));
    std::vector<float> helpRow;
    for(int col = 0; col < this->getColumns(); col++) {
        helpRow.emplace_back(1);
        col++;
    };

//    this->data.emplace_back(helpRow);
//    this->data = (*this*result).data;
//    this->data.erase(this->data.begin() + this->data.size()-1);
    //converteer terug naar 3x3 matrix
    result.data.erase(result.data.begin() + result.data.size() - 1);
    result.data[0].erase(result.data[0].begin() + result.data[0].size() - 1);
    result.data[1].erase(result.data[1].begin() + result.data[1].size() - 1);
    result.data[2].erase(result.data[2].begin() + result.data[2].size() - 1);

    this->translateMatrixXYZ(-p.x,-p.y,-p.z);

    Matrix r = result * *this;
    this->data = r.data;

    this->translateMatrixXYZ(p.x,p.y,p.z);
    return *this;
}

void Matrix3d::Update(float elapsedTime) {
    std::cout << "update self" << std::endl;
}

void Matrix3d::addPoint(Point3d p) {
    this->data[0].emplace_back(p.x);
    this->data[1].emplace_back(p.y);
    this->data[2].emplace_back(p.z);
}

void Matrix3d::setOrientationMatrix(Matrix3d *orientationMatrix) {
    hasOrientationMatrix = true;
    Matrix3d::orientationMatrix = orientationMatrix;
}

Matrix3d *Matrix3d::getOrientationMatrix() const {
    return orientationMatrix;
}

Point3d Matrix3d::getYAxis() {
    if(this->hasOrientationMatrix) {
        Point3d p1 = Point3d(orientationMatrix->data[0][0],orientationMatrix->data[1][0],orientationMatrix->data[2][0]);
        Point3d p2 = Point3d(orientationMatrix->data[0][8],orientationMatrix->data[1][8],orientationMatrix->data[2][8]);
        return p2 - p1;
    }
    return Point3d(0, 0, 0);
}

Point3d Matrix3d::getZAxis() {
    if(this->hasOrientationMatrix) {
        Point3d p1 = Point3d(orientationMatrix->data[0][6],orientationMatrix->data[1][6],orientationMatrix->data[2][6]);
        Point3d p2 = Point3d(orientationMatrix->data[0][5],orientationMatrix->data[1][5],orientationMatrix->data[2][5]);
        return p2 - p1;
    }
    return Point3d(0, 0, 0);
}

Point3d Matrix3d::getXAxis() {
    if(this->hasOrientationMatrix) {
        Point3d p1 = Point3d(orientationMatrix->data[0][2],orientationMatrix->data[1][2],orientationMatrix->data[2][2]);
        Point3d p2 = Point3d(orientationMatrix->data[0][3],orientationMatrix->data[1][3],orientationMatrix->data[2][3]);
        return p2 - p1;
    }
    return Point3d(0, 0, 0);
}

bool Matrix3d::checkCollision(Matrix3d other) {
    if(!isVisible || !other.isVisible)
        return false;
    std::vector<Point3d> a = this->getCollisionPoints();
    Point3d aMax = a[1];
    Point3d aMin = a[0];

    std::vector<Point3d> b = other.getCollisionPoints();
    Point3d bMax = b[1];
    Point3d bMin = b[0];
    //AABB vs AABB collisie detectie
    if((aMin.x <= bMax.x && aMax.x >= bMin.x) &&
            (aMin.y <= bMax.y && aMax.y >= bMin.y) &&
            (aMin.z <= bMax.z && aMax.z >= bMin.z)){
        isCollided();
        return true;
    }
    isOnCollision = false;
    return false;
}

std::vector<Point3d> Matrix3d::getCollisionPoints() {
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxZ;
    float maxY;
    bool firstrun = true;
    for(int i = 0; i < this->data[0].size(); i++){
        if(firstrun){
            maxX= this->data[0][i], minX = this->data[0][i];
            maxY = this->data[1][i], minY = this->data[1][i];
            maxZ = this->data[2][i], minZ = this->data[2][i];
            firstrun = false;
        }else{
            if(maxX < this->data[0][i])
                maxX = this->data[0][i];
            if(minX > this->data[0][i])
                minX = this->data[0][i];
            if(maxY < this->data[1][i])
                maxY = this->data[1][i];
            if(minY > this->data[1][i])
                minY = this->data[1][i];
            if(maxZ < this->data[2][i])
                maxZ = this->data[2][i];
            if(minZ > this->data[2][i])
                minZ = this->data[2][i];
        }
    }
    return std::vector<Point3d>({Point3d(minX,minY,minZ),Point3d(maxX,maxY,maxZ)});
}

void Matrix3d::isCollided() {
    isOnCollision = true;
}

void Matrix3d::destroy() {
    this->isVisible = false;
}

Matrix Matrix3d::fixFinalCalculation(Matrix m) {
    for(int i = 0; i < m.data[0].size(); i++){
        float _x = m.data[0][i];
        float _y = m.data[1][i];
        float _z = m.data[2][i];
        float _w = m.data[3][i];
        float scsz = RenderManager::GetScreenSize();
        m.data[0][i] = ((scsz/2) + ((_x+1.0f)/_w) * (scsz)) * (0.5);
        m.data[1][i] = ((scsz/2) + ((_y+1.0f)/_w) * (scsz)) * (0.5);
        m.data[2][i] = -_z;
    }
    return m;
}