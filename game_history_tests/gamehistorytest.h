#ifndef GAMEHISTORYTEST_H
#define GAMEHISTORYTEST_H

#include <iostream>

#include "gtest/gtest.h"
#include "../game_history/gamehistory.h"
#include "../game_history/player.h"

class GameHistoryTest : public :: testing::Test{
protected:
    GameHistoryTest();
    virtual ~GameHistoryTest();
    virtual void SetUp();
    virtual void TearDown();

    GameHistory* gameHistory;
};

#endif // GAMEHISTORYTEST_H
