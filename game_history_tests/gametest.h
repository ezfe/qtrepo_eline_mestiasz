#ifndef GAMETEST_H
#define GAMETEST_H

#include <iostream>

#include "gtest/gtest.h"
#include "../game_history/game.h"
#include "../game_history/player.h"

class GameTest : public :: testing::Test{
protected:
    GameTest();

    virtual ~GameTest();
    virtual void SetUp();
    virtual void TearDown();

    Game* game;

};

#endif // GAMETEST_H
