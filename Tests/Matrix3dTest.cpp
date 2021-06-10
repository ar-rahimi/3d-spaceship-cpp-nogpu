//
// Created by Mevlüt Özdemir on 24-02-18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Game/Matrix3d.h"

using testing::Eq;

namespace {
    class Matrix3dTest : public testing::Test {

    public:

        Matrix3dTest() {

        }
    };
}

TEST_F(Matrix3dTest, ItGeneratesCorrectColumnsAndRowsOnInitialize) {
    // last column should be skipped (eg: with 2's)

    Matrix3d first({Point3d(1, 1, 1, 2),
                    Point3d(2, 1, 1, 2),
                    Point3d(2, 2, 1, 2)});

    ASSERT_EQ(first.getRows(), 3);
    ASSERT_EQ(first.getColumns(), 3);
}

TEST_F(Matrix3dTest, ItCanScaleAMatrixByGivenFloatNumbers) {

    // [ 2 1 2 2 ]
    // [ 0 1 1 1 ]
    // [ 1 1 2 1 ]
    Matrix3d first({{2, 0, 1}, //top punt van schip gebruikt GetTopPoint van schip wordt gebruikt door w s-key
                    {1, 1, 1}, //left punt van schip gebruikt GetLeftPoint van schip wordt gebruikt door a en d-key
                    {2, 1, 2},
                    {2, 1, 1}});


    // [  2.5 1.25 2.5  2.5  ]
    // [    0 1.1  1.1  1.1  ]
    // [ 1.08 1.08 2.16 1.08  ]
    first.scaleMatrixXYZ(1.25, 1.10, 1.08);

    // first row
    ASSERT_EQ(first.getRowValues(0)[0], 2.5f);
    ASSERT_EQ(first.getRowValues(0)[1], 1.25f);
    ASSERT_EQ(first.getRowValues(0)[2], 2.5f);
    ASSERT_EQ(first.getRowValues(0)[3], 2.5f);

    // second row
    ASSERT_EQ(first.getRowValues(1)[0], 0);
    ASSERT_EQ(first.getRowValues(1)[1], 1.1f);
    ASSERT_EQ(first.getRowValues(1)[2], 1.1f);
    ASSERT_EQ(first.getRowValues(1)[3], 1.1f);

    // third row
    ASSERT_EQ(first.getRowValues(2)[0], 1.08f);
    ASSERT_EQ(first.getRowValues(2)[1], 1.08f);
    ASSERT_EQ(first.getRowValues(2)[2], 2.16f);
    ASSERT_EQ(first.getRowValues(2)[3], 1.08f);
}

TEST_F(Matrix3dTest, ItCanCalculateTheInproduct) {
    Point3d a({2, 3, 5});

    Matrix3d first({a});
    float result = Point3d::GetInProduct(a, a);

    // a.x^2 * a.y^2 * a.z^2 = 38
    ASSERT_EQ(result, 38);
}

TEST_F(Matrix3dTest, ItCanCalculateTheOutproduct) {
    Point3d a({5, 3, 2});

    Matrix3d first({a});
    auto result = Point3d::GetOutProduct(a, a);

    // x = a.y * b.z - a.z * b.y
    // y = a.z * b.x - a.x * b.z
    // z = a.x * b.y - a.y * b.x

//    std::cout << result.x << std::endl;
//    std::cout << result.y << std::endl;
//    std::cout << result.z << std::endl;

//    ASSERT_EQ(result.x, 38);
//    ASSERT_EQ(result.y, 38);
//    ASSERT_EQ(result.z, 38);
}

TEST_F(Matrix3dTest, ItCanTranslateAMatrixByGivenFloatNumbers) {

    // [ 4 1 6 1 ]
    // [ 0 3 3 1 ]
    // [ 1 2 5 1 ]
    Matrix3d first({{4, 0, 1}, //top punt van schip gebruikt GetTopPoint van schip wordt gebruikt door w s-key
                    {1, 3, 2}, //left punt van schip gebruikt GetLeftPoint van schip wordt gebruikt door a en d-key
                    {6, 3, 5},
                    {1, 1, 1}});


    // [ 5.1  2.1  7.1  2.1  ]
    // [ 1.28 4.28 4.28 2.28 ]
    // [ 2.89 3.89 6.89 2.89 ]
    first.translateMatrixXYZ(1.10, 1.28, 1.89);

    // first row
    ASSERT_EQ(first.getRowValues(0)[0], 5.1f);
    ASSERT_EQ(first.getRowValues(0)[1], 2.1f);
    ASSERT_EQ(first.getRowValues(0)[2], 7.1f);
    ASSERT_EQ(first.getRowValues(0)[3], 2.1f);

//    // second row
//    ASSERT_EQ(first.getRowValues(1)[0], 1.28f);
//    ASSERT_EQ(first.getRowValues(1)[1], 4.28f);
//    ASSERT_EQ(first.getRowValues(1)[2], 4.28f);
//    ASSERT_EQ(first.getRowValues(1)[3], 2.28f);
//
//    // third row
//    ASSERT_FLOAT_EQ(first.getRowValues(2)[0], 2.89);
//    ASSERT_EQ(first.getRowValues(2)[0], 2.89);
//    ASSERT_EQ(first.getRowValues(2)[1], 3.89f);
//    ASSERT_EQ(first.getRowValues(2)[2], 6.89f);
//    ASSERT_EQ(first.getRowValues(2)[3], 2.89f);
}
