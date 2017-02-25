#ifndef PLAYERGAMEHISTORYTEST_H
#define PLAYERGAMEHISTORYTEST_H

#include <iostream>

#include "gtest/gtest.h"
#include "../game_history/playergamehistory.h"
#include "../game_history/player.h"

class PlayerGameHistoryTest : public :: testing::Test{
protected:

    PlayerGameHistoryTest();
    virtual ~PlayerGameHistoryTest();
    virtual void SetUp();
    virtual void TearDown();

    PlayerGameHistory* playerGameHistory;
};

#endif // PLAYERGAMEHISTORYTEST_H
