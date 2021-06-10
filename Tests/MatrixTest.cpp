//
// Created by Mevlüt Özdemir on 24-02-18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Game/Matrix3d.h"

using testing::Eq;

namespace {
    class MatrixTest : public testing::Test {

    public:

        MatrixTest() {

        }
    };
}


TEST_F(MatrixTest, ItGeneratesCorrectColumnsAndRowsOnInitialize) {
    Matrix first(2, 3);

    ASSERT_EQ(first.getRows(), 2);
    ASSERT_EQ(first.getColumns(), 3);
}

TEST_F(MatrixTest, ItCanMultiplyWithOtherMatrix) {
    Matrix first(2, 2);
    Matrix second(2, 3);

    //  [ 4 1 ]
    //  [ 2 3 ]
    first.insertNumber(4, 0, 0);
    first.insertNumber(1, 0, 1);
    first.insertNumber(2, 1, 0);
    first.insertNumber(3, 1, 1);

    // [ 3 0 4 ]
    // [ 2 5 1 ]
    second.insertNumber(3, 0, 0);
    second.insertNumber(0, 0, 1);
    second.insertNumber(4, 0, 2);
    second.insertNumber(2, 1, 0);
    second.insertNumber(5, 1, 1);
    second.insertNumber(1, 1, 2);

    // [ 14 5 17 ]
    // [ 12 15 11 ]
    auto result = first * second;

    ASSERT_EQ(result.getRows(), 2);
    ASSERT_EQ(result.getColumns(), 3);
    ASSERT_EQ(result.getRowValues(0)[0], 14);
    ASSERT_EQ(result.getRowValues(0)[1], 5);
    ASSERT_EQ(result.getRowValues(0)[2], 17);
    ASSERT_EQ(result.getRowValues(1)[0], 12);
    ASSERT_EQ(result.getRowValues(1)[1], 15);
    ASSERT_EQ(result.getRowValues(1)[2], 11);
}


TEST_F(MatrixTest, ItReturnsTheCorrectRowValues) {
    Matrix first(2, 2);
    first.insertNumber(8, 0, 0);
    first.insertNumber(9, 0, 1);
    first.insertNumber(4, 1, 0);
    first.insertNumber(5, 1, 1);

    ASSERT_EQ(first.getRowValues(1)[0], 4);
    ASSERT_EQ(first.getRowValues(1)[1], 5);
}

TEST_F(MatrixTest, ItCanScaleItByAgivenFloatingNumber) {

    Matrix first(2, 3);

    // [ 15 20 ]
    // [  9  4 ]
    first.insertNumber(15, 0, 0);
    first.insertNumber(20, 0, 1);
    first.insertNumber(9, 1, 0);
    first.insertNumber(4, 1, 1);
    first.scaleMatrixBy(1.5);

    // [ 22.5 30 ]
    // [ 13.5  6 ]
    ASSERT_EQ(first.getRowValues(0)[0], 22.5);
    ASSERT_EQ(first.getRowValues(0)[1], 30);
    ASSERT_EQ(first.getRowValues(1)[0], 13.5);
    ASSERT_EQ(first.getRowValues(1)[1], 6);
}

