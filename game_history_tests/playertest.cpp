#include "playertest.h"

PlayerTest::PlayerTest(){
    player = new Player("Foo", "Boo", "111 Quad Drive");
}

PlayerTest::~PlayerTest(){
    try {
        delete player;
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void PlayerTest::SetUp(){

}

void PlayerTest::TearDown(){

}

TEST_F(PlayerTest, TEST_ADD_GAME){
    player->add_game(new Game(player, "robots", 11));

    EXPECT_TRUE(player->get_recent_game()->get_name() == "robots")
            << "Did not add game Correctly";
    EXPECT_TRUE(player->get_recent_game()->get_score() == 11)
            << "Did not add game Correctly";
    EXPECT_TRUE(player->get_games()->get_games().size() == 1)
            << "Did not add game Correctly";
}
