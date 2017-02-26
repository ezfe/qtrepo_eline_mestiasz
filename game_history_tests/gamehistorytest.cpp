#include "gamehistorytest.h"

GameHistoryTest::GameHistoryTest(){
    gameHistory = new GameHistory();
}

GameHistoryTest::~GameHistoryTest(){
    delete gameHistory;
}

void GameHistoryTest::SetUp(){

}

void GameHistoryTest::TearDown(){

}

TEST_F(GameHistoryTest, TEST_ADD_GAME){
    gameHistory->add_game(new Game(nullptr, "robots", 11));

    EXPECT_TRUE(gameHistory->get_games().back()->get_name() == "robots")
            << "Did not add game Correctly";
    EXPECT_TRUE(gameHistory->get_games().back()->get_score() == 11)
            << "Did not add game Correctly";
    EXPECT_TRUE(gameHistory->get_games().size() == 1)
            << "Did not add game Correctly";
}
