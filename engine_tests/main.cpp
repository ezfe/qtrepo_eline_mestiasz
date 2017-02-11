#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "../engines/robots.h"
#include "../engines/worms.h"

// The fixture for testing class Foo.
class RobotsTest : public ::testing::Test {
protected:

    RobotsTest() {

    }

    virtual ~RobotsTest() {

    }

    virtual void SetUp() {
        robots.redraw();
    }

    virtual void TearDown() {

    }

    Robots robots;

};

class WormsTest : public ::testing::Test {
protected:
    WormsTest() {

    }

    virtual ~WormsTest() {

    }

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    Worms worms;
};

/****************
 * Robots Tests *
 ****************/

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

TEST_F(RobotsTest, TEST_PRINT_GAMEBOARD){
    std::string str = robots.printGameboard();
    std::string expected = "#0:   0/  | 1/  | 2/  | \n"
                           "#1:   0/  | 1/  | 2/  | \n"
                           "#2:   0/  | 1/  | 2/  | \n"
                           "#3:   0/  | 1/  | 2/  | \n"
                           "#4:   0/  | 1/  | 2/  | \n";
    EXPECT_EQ(expected, str) << "The string representation of the gameboard is wrong!";
}

TEST_F(RobotsTest, TEST_FIND_EMPTY_CELL){
    int counter = 0;
    while(!robots.findEmptyCell().empty()){
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
}


TEST_F(RobotsTest, TEST_KILL_ROBOT){
    robots.setItem(0, 0, '+');
    robots.killRobot(0, 0);
    EXPECT_EQ(' ', robots.getItem(0, 0)) << "Robot should have been removed from this cell";
}

TEST_F(RobotsTest, TEST_FIND_CELL_TO_MOVE){
    robots.setItem(0, 0, '@');
    robots.setItem(4, 4, '+');
    robots.setItem(0, 2, '+');

    std::vector<int> position_01 = robots.findCellToMove(4, 4);
    std::vector<int> position_02 = robots.findCellToMove(1, 2);

    EXPECT_TRUE(3 == position_01.at(0) && 3 == position_01.at(1)) << "The cell was not generated correctly";
    EXPECT_TRUE(3 == position_02.at(0) && 3 == position_02.at(2)) << "The cell was not generated correctly";
}

<<<<<<< HEAD
TEST_F(RobotsTest, TEST_GENERATE_ROBOT_POSITION){
    for(int i = 0; i < ROWS * COLS; i++){
        std::vector<int> tmp = robots.generateRobotPosition();
        EXPECT_TRUE(!tmp.empty()) << "The returned vector should not be null as there is enough space";
    }

    std::vector<int> tmp = robots.generateRobotPosition();
    EXPECT_TRUE(tmp.empty()) << "The returned vector should be empty as there is no empty cell left";
}

TEST_F(RobotsTest, TEST_GENERATE_PLAYER_POSITION){
    for(int i = 0; i < ROWS * COLS; i++){
        std::vector<int> tmp = robots.generatePlayerPosition();
        EXPECT_TRUE(!tmp.empty()) << "The returned vector should not be null as there is enough space";
    }

    std::vector<int> tmp = robots.generatePlayerPosition();
    EXPECT_TRUE(tmp.empty()) << "The returned vector should be empty as there is no empty cell left";
}

/****************
 * Worms Tests *
 ****************/

TEST_F(WormsTest, TESTA) {
    EXPECT_EQ(1, 1) << "Equal Ints";
}

=======
>>>>>>> master
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
