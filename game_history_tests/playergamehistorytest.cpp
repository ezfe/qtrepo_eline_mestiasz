#include "playergamehistorytest.h"

PlayerGameHistoryTest::PlayerGameHistoryTest(){
    playerGameHistory = new PlayerGameHistory();
}

PlayerGameHistoryTest::~PlayerGameHistoryTest(){
   delete playerGameHistory;
}

void PlayerGameHistoryTest::SetUp(){

}

void PlayerGameHistoryTest::TearDown(){

}

TEST_F(PlayerGameHistoryTest, TEST_NUMBER_GAMES_PLAYED){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 31);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->number_games_played(), 4)
            << "Could not find correct number ";

    game = new Game(player, "robots", 141);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->number_games_played(), 5)
            << "Could not find correct number";
}

TEST_F(PlayerGameHistoryTest, TEST_NUMBER_PLAYERS_PLAYED){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 31);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->number_players_played(), 2) << "Could not find correct number";
}

TEST_F(PlayerGameHistoryTest, TEST_TOP_GAME_SCORE){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 31);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->top_game_score(), 31)
            << "Could not find correct average";

    game = new Game(player, "worms", 41);
    playerGameHistory->add_game(player, game);
    EXPECT_EQ(playerGameHistory->top_game_score(), 41)
            << "Could not find correct average";

}

TEST_F(PlayerGameHistoryTest, TEST_AVG_GAMES_PER_PLAYER){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->avg_games_per_player(), 2)
            << "Could not find correct average";
}

TEST_F(PlayerGameHistoryTest, TEST_AVG_SCORE_PER_PLAYER){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);


    EXPECT_EQ(playerGameHistory->avg_score_per_player(player), 6)
            << "Could not find correct average";

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->avg_score_per_player(player), 6)
            << "Could not find correct average";
}

TEST_F(PlayerGameHistoryTest, TEST_AVG_GAME_SCORE){
    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    player = new Player("Miss", "Rogbeer", "17");
    game = new Game(player, "worms", 11);
    playerGameHistory->add_game(player, game);

    game = new Game(player, "robots", 1);
    playerGameHistory->add_game(player, game);

    EXPECT_EQ(playerGameHistory->avg_game_score(), 6)
            << "Could not find correct average";
}

TEST_F(PlayerGameHistoryTest, TEST_ADD_GAME){
    EXPECT_TRUE(playerGameHistory->get_games().size() == 0)
            << "Did not initialize correctly";
    EXPECT_TRUE(playerGameHistory->get_players().size() == 0)
            << "Did not initialize correctly";

    Player* player = new Player("Mr", "Anderson", "Matrix");
    Game* game = new Game(player, "robots", 11);

    playerGameHistory->add_game(player, game);
    EXPECT_TRUE(playerGameHistory->get_games().size() == 1)
            << "Did not add game and player correctly";
    EXPECT_TRUE(playerGameHistory->get_players().size() == 1)
            << "Did not add game and player correctly";

    game = new Game(player, "robots", 11);
    playerGameHistory->add_game(player, game);
    EXPECT_TRUE(playerGameHistory->get_games().size() == 2)
            << "Did not add game and player correctly";
    EXPECT_TRUE(playerGameHistory->get_players().size() == 1)
            << "Did not add game and player correctly";

}
