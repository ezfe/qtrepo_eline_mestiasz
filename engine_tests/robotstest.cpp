#include "robotstest.h"

RobotsTest::RobotsTest() {
    robots = new Robots(10, 10, 7);
}

RobotsTest::~RobotsTest() {
    delete robots;
}

void RobotsTest::SetUp() {
    robots->redraw();
}

void RobotsTest::TearDown() {

}


/****************
 * Robots Tests *
 ****************/

TEST_F(RobotsTest, TEST_PRINT_GAMEBOARD){
    std::string str = robots->print_gameboard();
    std::string expected = "############\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "#          #\n"
                           "############\n";
    EXPECT_EQ(expected, str) << "The string representation of the gameboard is wrong!";
}

TEST_F(RobotsTest, TEST_FIND_EMPTY_CELL){
    int counter = 0;
    std::pair<int, int> cell = robots->find_empty_cell();

    while(cell.first != -1 && cell.second != -1){
        robots->set_item(cell.first, cell.second, '+');
        cell = robots->find_empty_cell();
        counter++;
    }

    EXPECT_EQ(robots->get_width() * robots->get_height(), counter) << "The number of empty places should equal to total number of cells";
}


TEST_F(RobotsTest, TEST_MOVE_ROBOT){
    robots->set_item(0, 0, '+');
    robots->move_robot(0, 0, 2, 2);
    EXPECT_EQ(' ', robots->get_item(0, 0)) << "Robot should have left this cell";
    EXPECT_EQ(false, robots->if_moved(0, 0)) << "The robot left this position, so it should become false";
    EXPECT_EQ('+', robots->get_item(2, 2)) << "Robot should have been placed here";
    EXPECT_EQ(true, robots->if_moved(2, 2)) << "The robot moved to this position, so it should become true";

    robots->move_robot(2, 2, 11, 3);
    EXPECT_EQ('+', robots->get_item(2, 2)) << "Robot cannot leave the grid";
    EXPECT_EQ(true, robots->if_moved(2, 2)) << "This value should stay true";
}


TEST_F(RobotsTest, TEST_KILL_ROBOT){
    robots->set_item(0, 0, '+');
    robots->kill_robot(0, 0);
    EXPECT_EQ('*', robots->get_item(0, 0)) << "Robot should have been removed from this cell";
}

TEST_F(RobotsTest, TEST_FIND_CELL_TO_MOVE){
    robots->set_item(0, 0, '@');
    robots->set_item(2, 2, '+');
    robots->set_item(0, 2, '+');

    std::pair<int, int> position_01 = robots->find_cell_to_move(2, 2);
    std::pair<int, int> position_02 = robots->find_cell_to_move(1, 2);

    EXPECT_TRUE(1 == position_01.first && 1 == position_01.second) << "The cell was not generated correctly";
    EXPECT_TRUE(0 == position_02.first && 1 == position_02.second) << "The cell was not generated correctly";
}

TEST_F(RobotsTest, TEST_MOVE){
    robots->set_item(2, 2, '@');
    robots->move(1, 1);
    EXPECT_TRUE(robots->get_current_position().first != 2 || robots->get_current_position().second != 2) << "The player should have changed position";

    robots->move(-1, 0);
    EXPECT_TRUE(robots->get_current_position().first == 1 && robots->get_current_position().second == 1) << "The player should not leave the grid";
}

TEST_F(RobotsTest, TEST_TELEPORT){
    for(int i = 0; i < robots->get_height(); i++){
        for(int j = 0; j < robots->get_width(); j++){
            robots->set_item(i, j, '+');
        }
    }

    robots->set_item(2, 2, '@');
    robots->teleport();
    EXPECT_FALSE(robots->is_alive()) << "Player did not teleport correctly";
}

TEST_F(RobotsTest, TEST_REDRAW) {
    for(int i = 0; i != robots->get_height(); i++){
        std::cout << "#" << i << ":   ";
        for(int j =0; j != robots->get_width(); j++){
            EXPECT_EQ(' ', robots->get_item(i, j)) << "Every cell should be initialized to space!";
            EXPECT_EQ(false, robots->if_moved(i, j)) << "Every cell's bool value should be initialized false";
            std::cout << j << "/" << robots->get_item(i, j) << " | ";
        }
        std::cout << std::endl;
    }

    EXPECT_EQ(0, robots->get_level()) << "Level counter should return to its initial value 0!";
    EXPECT_EQ(true, robots->is_alive()) << "Alive value should return to its initial value - true";
    EXPECT_EQ(0, robots->get_score()) << "Score value should return to its initial value - 0";

}

TEST_F(RobotsTest, TEST_CHECK_WINNER){
    robots->set_item(2, 2, '@');
    EXPECT_EQ(1, robots->check_winner()) << "The player should have won, as he/she is the only one on the gameboard";

    robots->set_item(1, 1, '+');
    EXPECT_EQ(0, robots->check_winner()) << "The game has not finished yet as there is one robot left, and player alive";

    robots->set_item(2, 2, ' ');
    robots->die();
    EXPECT_EQ(2, robots->check_winner()) << "The robots win, as there is no player left";
}

TEST_F(RobotsTest, TEST_CHECK_CELL){
    robots->set_item(2, 2, '@');
    robots->set_item(0, 0, '+');
    robots->set_item(0, 1, '+');
    robots->set_item(0, 2, '+');

    robots->move(1, 2);
    EXPECT_TRUE(robots->get_current_position().first == 2 && robots->get_current_position().second == 2) << "The cell checker did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_W){
    robots->set_item(2, 2, '@');
    robots->set_item(0, 0, '+');
    robots->set_item(0, 1, '+');
    robots->set_item(0, 2, '+');

    robots->controller('w');
    EXPECT_TRUE(robots->check_winner() != 0) << "The controller did not work correctly";

}


TEST_F(RobotsTest, TEST_CONTROLLER_CMD_Y){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(4, 4, '+');

    robots->controller('y');
    EXPECT_TRUE(robots->get_current_position().first == 1 && robots->get_current_position().second == 1) << "The controller did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_U){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(4, 4, '+');

    robots->controller('u');
    EXPECT_TRUE(robots->get_current_position().first == 1 && robots->get_current_position().second == 3) << "The controller did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_H){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(4, 4, '+');

    robots->controller('h');
    EXPECT_TRUE(robots->get_current_position().first == 2 && robots->get_current_position().second == 1) << "The controller did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_J){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(0, 0, '+');

    robots->controller('j');
    EXPECT_TRUE(robots->get_current_position().first == 3 && robots->get_current_position().second == 2) << "The controller did not work correctly"
                                                                                                         << robots->get_current_position().first
                                                                                                         << robots->get_current_position().second;

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_K){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(0, 0, '+');

    robots->controller('k');
    EXPECT_TRUE(robots->get_current_position().first == 1 && robots->get_current_position().second == 2) << "The controller did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_L){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(4, 4, '+');

    robots->controller('l');
    EXPECT_TRUE(robots->get_current_position().first == 2 && robots->get_current_position().second == 3) << "The controller did not work correctly";

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_B){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(4, 4, '+');

    robots->controller('b');
    EXPECT_TRUE(robots->get_current_position().first == 3 && robots->get_current_position().second == 1) << "The controller did not work correctly "
                                                                                                         << robots->get_current_position().first
                                                                                                         << robots->get_current_position().second;

}

TEST_F(RobotsTest, TEST_CONTROLLER_CMD_N){
    robots->set_item(2, 2, '@');
    robots->set_current_position(2, 2);
    robots->set_item(0, 0, '+');

    robots->controller('n');
    EXPECT_TRUE(robots->get_current_position().first == 3 && robots->get_current_position().second == 3) << "The controller did not work correctly "
                                                                                                         << robots->get_current_position().first
                                                                                                         << robots->get_current_position().second;

}
