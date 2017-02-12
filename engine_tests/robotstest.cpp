#include "robotstest.h"

RobotsTest::RobotsTest() {

}

RobotsTest::~RobotsTest() {

}

void RobotsTest::SetUp() {
    robots.redraw();
}

void RobotsTest::TearDown() {

}


/****************
 * Robots Tests *
 ****************/

TEST_F(RobotsTest, TEST_PRINT_GAMEBOARD){
    std::string str = robots.printGameboard();
    std::string expected = "#0:             \n"
                           "#1:             \n"
                           "#2:             \n"
                           "#3:             \n"
                           "#4:             \n"
                           "#5:             \n"
                           "#6:             \n"
                           "#7:             \n"
                           "#8:             \n"
                           "#9:             \n";
    EXPECT_EQ(expected, str) << "The string representation of the gameboard is wrong!";
}

TEST_F(RobotsTest, TEST_FIND_EMPTY_CELL){
    int counter = 0;
    std::pair<int, int> cell = robots.findEmptyCell();

    while(cell.first != -1 && cell.second != -1){
        robots.setItem(cell.first, cell.second, '+');
        cell = robots.findEmptyCell();
        counter++;
    }

    EXPECT_EQ(ROWS * COLS, counter) << "The number of empty places should equal to total number of cells";
}


TEST_F(RobotsTest, TEST_MOVE_ROBOT){
    robots.setItem(0, 0, '+');
    robots.moveRobot(0, 0, 2, 2);
    EXPECT_EQ(' ', robots.getItem(0, 0)) << "Robot should have left this cell";
    EXPECT_EQ(false, robots.ifMoved(0, 0)) << "The robot left this position, so it should become false";
    EXPECT_EQ('+', robots.getItem(2, 2)) << "Robot should have been placed here";
    EXPECT_EQ(true, robots.ifMoved(2, 2)) << "The robot moved to this position, so it should become true";

    robots.moveRobot(2, 2, 11, 3);
    EXPECT_EQ('+', robots.getItem(2, 2)) << "Robot cannot leave the grid";
    EXPECT_EQ(true, robots.ifMoved(2, 2)) << "This value should stay true";
}


TEST_F(RobotsTest, TEST_KILL_ROBOT){
    robots.setItem(0, 0, '+');
    robots.killRobot(0, 0);
    EXPECT_EQ('*', robots.getItem(0, 0)) << "Robot should have been removed from this cell";
}

TEST_F(RobotsTest, TEST_FIND_CELL_TO_MOVE){
    robots.setItem(0, 0, '@');
    robots.setItem(2, 2, '+');
    robots.setItem(0, 2, '+');

    std::pair<int, int> position_01 = robots.findCellToMove(2, 2);
    std::pair<int, int> position_02 = robots.findCellToMove(1, 2);

    EXPECT_TRUE(1 == position_01.first && 1 == position_01.second) << "The cell was not generated correctly";
    EXPECT_TRUE(0 == position_02.first && 1 == position_02.second) << "The cell was not generated correctly";
}

TEST_F(RobotsTest, TEST_MOVE){
    robots.setItem(2, 2, '@');
    robots.move(1, 1);
    EXPECT_TRUE(robots.getCurrentPosition().first != 2 || robots.getCurrentPosition().second != 2) << "The player should have changed position";

    robots.move(-1, 0);
    EXPECT_TRUE(robots.getCurrentPosition().first == 1 && robots.getCurrentPosition().second == 1) << "The player should not leave the grid";
}

TEST_F(RobotsTest, TEST_TELEPORT){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            robots.setItem(i, j, '+');
        }
    }

    robots.setItem(2, 2, '@');
    robots.setItem(1, 1, ' ');
    robots.teleport();
    EXPECT_TRUE(robots.getCurrentPosition().first == 1 && robots.getCurrentPosition().second == 1) << "Player did not teleport correctly";
    robots.setItem(2, 2, '+');
    robots.teleport();
    EXPECT_TRUE(robots.getCurrentPosition().first == 1 && robots.getCurrentPosition().second == 1) << "Player should not have teleported correctly";
}

TEST_F(RobotsTest, TEST_REDRAW) {
    for(int i = 0; i != ROWS; i++){
        std::cout << "#" << i << ":   ";
        for(int j =0; j != COLS; j++){
            EXPECT_EQ(' ', robots.getItem(i, j)) << "Every cell should be initialized to space!";
            EXPECT_EQ(false, robots.ifMoved(i, j)) << "Every cell's bool value should be initialized false";
            std::cout << j << "/" << robots.getItem(i, j) << " | ";
        }
        std::cout << std::endl;
    }

    EXPECT_EQ(0, robots.getLevel()) << "Level counter should return to its initial value 0!";
    EXPECT_EQ(true, robots.isAlive()) << "Alive value should return to its initial value - true";
    EXPECT_EQ(0, robots.getScore()) << "Score value should return to its initial value - 0";

}

TEST_F(RobotsTest, TEST_CHECK_WINNER){
    robots.setItem(2, 2, '@');
    EXPECT_EQ(1, robots.checkWinner()) << "The player should have won, as he/she is the only one on the gameboard";

    robots.setItem(1, 1, '+');
    EXPECT_EQ(0, robots.checkWinner()) << "The game has not finished yet as there is one robot left, and player alive";

    robots.setItem(2, 2, ' ');
    robots.die();
    EXPECT_EQ(2, robots.checkWinner()) << "The robots win, as there is no player left";
}
