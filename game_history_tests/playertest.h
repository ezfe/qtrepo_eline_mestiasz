#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include <iostream>

#include "gtest/gtest.h"
#include "../game_history/player.h"
#include "../game_history/game.h"

class PlayerTest : public :: testing::Test{

protected:
    PlayerTest();
    virtual ~PlayerTest();
    virtual void SetUp();
    virtual void TearDown();

    Player* player;
};

#endif // PLAYERTEST_H
