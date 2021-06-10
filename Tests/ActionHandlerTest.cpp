//
// Created by Mevlüt Özdemir on 24-02-18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Game/SpaceShipInputHandlers/ActionHandlerFactory.h"

using testing::Eq;

namespace {
    class ActionHandlerTest : public testing::Test {

    public:

        ActionHandlerTest() {

        }
    };
}


TEST_F(ActionHandlerTest, ItReturnsTheCorrectActionHandler) {
    auto actionHandler = ActionHandlerFactory::Instance();

    auto action = actionHandler->GetAction(Controls::Top);
    ASSERT_EQ(action->getName(), "move-top");

    action = actionHandler->GetAction(Controls::TurnRight);
    ASSERT_EQ(action->getName(), "turn_right");

    action = actionHandler->GetAction(Controls::TurnLeft);
    ASSERT_EQ(action->getName(), "turn_left");

    action = actionHandler->GetAction(Controls::Bottom);
    ASSERT_EQ(action->getName(), "move-bottom");

    action = actionHandler->GetAction(Controls::ScaleUp);
    ASSERT_EQ(action->getName(), "scale-up");

    action = actionHandler->GetAction(Controls::ScaleDown);
    ASSERT_EQ(action->getName(), "scale-down");

    action = actionHandler->GetAction(Controls::Pitch);
    ASSERT_EQ(action->getName(), "pitch");

    action = actionHandler->GetAction(Controls::Yaw);
    ASSERT_EQ(action->getName(), "yaw");

    action = actionHandler->GetAction(Controls::Roll);
    ASSERT_EQ(action->getName(), "roll");

    action = actionHandler->GetAction(Controls::Space);
    ASSERT_EQ(action->getName(), "shoot");
}

TEST_F(ActionHandlerTest, ItAddsABulletOnShootAction) {
    auto actionHandler = ActionHandlerFactory::Instance();
    auto action = actionHandler->GetAction(Controls::Space);

    SpaceShip spaceShip;

    ASSERT_EQ(spaceShip.getDrawables().size(), 0);
    action->handle(spaceShip);
    ASSERT_EQ(spaceShip.getDrawables().size(), 1);
}

TEST_F(ActionHandlerTest, ItCanShootMultipleBullets) {
    auto actionHandler = ActionHandlerFactory::Instance();
    auto action = actionHandler->GetAction(Controls::Space);

    SpaceShip spaceShip;

    ASSERT_EQ(spaceShip.getDrawables().size(), 0);
    int max = 10;
    for (int i = 0; i < max ; ++i) {
        action->handle(spaceShip);
    }
    ASSERT_EQ(spaceShip.getDrawables().size(), 10);
}