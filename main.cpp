#include "Game/Game.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#undef main

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    Game game;
    game.Start();

    return 0;
}