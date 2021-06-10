//
// Created by Ahmad Rahimi on 2/23/18.
//

#include "headers/MatrixFactory.h"

Matrix3d MatrixFactory::GetCubeMatrix(float xScale, float yScale, float zScale) {
    Matrix3d m = Matrix3d({Point3d(1, 1, 1),
                           Point3d(2, 1, 1),
                           Point3d(2, 2, 1),
                           Point3d(1, 2, 1),
                           Point3d(1, 1, 1),
                           Point3d(1, 1, 2),
                           Point3d(2, 1, 2),
                           Point3d(2, 1, 1),
                           Point3d(2, 1, 2),
                           Point3d(2, 2, 2),
                           Point3d(2, 2, 1),
                           Point3d(2, 2, 2),
                           Point3d(1, 2, 2),
                           Point3d(1, 2, 1),
                           Point3d(1, 2, 2),
                           Point3d(1, 1, 2)});
    m.scaleMatrixXYZ(xScale, yScale, zScale);
    return m;
}

Matrix3d MatrixFactory::GetTriangleMatrix(float xScale, float yScale, float zScale) {
    Matrix3d m = Matrix3d({{1.5,0,1}, //top punt van schip gebruikt GetTopPoint van schip wordt gebruikt door w s-key
                  {1,1,1}, //left punt van schip gebruikt GetLeftPoint van schip wordt gebruikt door a en d-key
                  {1.5,1,2},
                  {2,1,1},
                  {1,1,1},
                  {1.5,0,1},
                  {2,1,1},
                  {1.5,0,1},
                  {1.5,1,2}});
    m.scaleMatrixXYZ(xScale,yScale,zScale);

    return m;
}


Matrix3d MatrixFactory::GetShipMatrix(float xScale, float yScale, float zScale) {
    Matrix3d m = Matrix3d({{1.5,0,1}, //top punt van schip gebruikt GetTopPoint van schip wordt gebruikt door w s-key
                           {1,1,1},
                           {1.25,0.75,1.25},
                           {1.5,1,2},
                           {1.75,0.75,1.25},
                           {2,1,1},
                           {1,1,1},
                           {1.5,0,1},
                           {2,1,1},
                           {1.5,0,1},
                           {1.5,1,2}});
    Matrix3d *o = new Matrix3d({
                                {1.5,-0.5,1}, //voorkant
                                {1.5,0.5,1}, //middelpunt
                                {1.5,0.5,2.5}, //links
                                {1.5,0.5,-0.5}, //rechts
                                {1.5,0.5,1}, //middelpunt
                                {3,0.5,1}, //boven
                                {0,0.5,1}, //beneden
                                {1.5,0.5,1}, //middelpunt
                                {1.5,1.5,1} //achterkant
                               });
    m.setOrientationMatrix(o);
    m.scaleMatrixXYZCenter(xScale,yScale,zScale);
    return m;
}

Matrix3d MatrixFactory::GetBulletMatrix(float xScale, float yScale, float zScale) {
    Matrix3d m =Matrix3d({Point3d(1, 1, 1),
                     Point3d(1.5, 1, 1),
                     Point3d(1.5, 3, 1),
                     Point3d(1, 3, 1),
                     Point3d(1, 1, 1),
                     Point3d(1, 1, 1.5),
                     Point3d(1.5, 1, 1.5),
                     Point3d(1.5, 1, 1),
                     Point3d(1.5, 1, 1.5),
                     Point3d(1.5, 3, 1.5),
                     Point3d(1.5, 3, 1),
                     Point3d(1.5, 3, 1.5),
                     Point3d(1, 3, 1.5),
                     Point3d(1, 3, 1),
                     Point3d(1, 3, 1.5),
                     Point3d(1, 1, 1.5),
                     Point3d(0.75,0.50,1.75),
                     Point3d(1.25,0.0,1.25),
                     Point3d(1.75,0.50,1.75),
                     Point3d(1.5,1,1.5),
                     Point3d(1.5,1,1),
                     Point3d(1.75,0.50,0.75),
                     Point3d(1.25,0.0,1.25),
                     Point3d(0.75,0.50,0.75),
                     Point3d(1,1,1),
                     Point3d(0.75,0.50,0.75),
                     Point3d(0.75,0.50,1.75),
                     Point3d(1.75,0.50,1.75),
                     Point3d(1.75,0.50,0.75),
                     Point3d(0.75,0.50,0.75),
                    });
    m.scaleMatrixXYZ(xScale,yScale,zScale);
    return m;
}
