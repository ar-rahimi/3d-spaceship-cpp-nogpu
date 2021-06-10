//
// Created by Mevlüt Özdemir on 24-02-18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace {
    class ClassName : public testing::Test {

    public:

        ClassName() {

        }
    };
}

TEST_F(ClassName, NameOfTestMethod) {

}