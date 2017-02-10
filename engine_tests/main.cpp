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

TEST_F(RobotsTest, TESTREDRAW) {
    for(int i = 0; i != ROWS; i++){
        std::cout << "#" << i << ":   ";
        for(int j =0; j != COLS; j++){
            EXPECT_EQ(' ', robots.getItem(i, j)) << "Every cell should be initialized to space!";
            std::cout << j << "/" << robots.getItem(i, j) << " | ";
        }
        std::cout << std::endl;
    }

    EXPECT_EQ(0, robots.getLevel()) << "Level counter should return to its initial value 0!";
    EXPECT_EQ(true, robots.isAlive()) << "Alive value should return to its initial value - true";
    EXPECT_EQ(0, robots.getScore()) << "Score value should return to its initial value - 0";

}


TEST_F(RobotsTest, TESTSETITEM){
    EXPECT_EQ(' ', robots.getItem(0, 0)) << "After redraw gameboard[0][0] should equal to space";
    robots.setItem(0, 0, '@');
    EXPECT_EQ(' ', robots.getItem(0,0)) << "The new value for gameboard[0][0] should equal to @";
}

TEST_F(RobotsTest, TESTGETITEM){
    EXPECT_EQ(' ', robots.getItem(0, 0)) << "After redraw gameboard[0][0] should equal to space";
}

TEST_F(RobotsTest, TESTPRINTGAMEBOARD){
    std::string str = robots.printGameboard();
    std::string expected = "#0:   0/  | 1/  | 2/  | \n"
                           "#1:   0/  | 1/  | 2/  | \n"
                           "#2:   0/  | 1/  | 2/  | \n"
                           "#3:   0/  | 1/  | 2/  | \n"
                           "#4:   0/  | 1/  | 2/  | \n";
    EXPECT_EQ(expected, str) << "The string representation of the gameboard is wrong!";
}

TEST_F(RobotsTest, TESTFINDEMPTYCELL){
    int counter = 0;
    while(!robots.findEmptyCell().empty()){
        counter++;
    }
    EXPECT_EQ(ROWS*COLS, counter) << "The number of empty places should equal to total number of cells";
}


TEST_F(RobotsTest, TESTMOVEROBOT){
    robots.setItem(0, 0, '+');
    robots.moveRobot(0, 0, 2, 2);
    EXPECT_EQ('+', robots.getItem(2, 2)) << "Robot should have been placed here";
}


TEST_F(RobotsTest, TESTKILLROBOT){
    robots.setItem(0, 0, '+');
    robots.killRobot(0, 0);
    EXPECT_EQ(' ', robots.getItem(0, 0)) << "Robot should have been removed from this cell";
}

TEST_F(RobotsTest, TESTFINDCELLTOMOVE){
    robots.setItem(0, 0, '@');
    robots.setItem(4, 4, '+');
    robots.setItem(0, 2, '+');

    std::vector<int> position_01 = robots.findCellToMove(4, 4);
    std::vector<int> position_02 = robots.findCellToMove(1, 2);

    EXPECT_TRUE(3 == position_01.at(0) && 3 == position_01.at(1)) << "The cell was not generated correctly";
    EXPECT_TRUE(3 == position_02.at(0) && 3 == position_02.at(2)) << "The cell was not generated correctly";
}

/****************
 * Worms Tests *
 ****************/

TEST_F(WormsTest, TESTA) {
    EXPECT_EQ(1, 1) << "Equal Ints";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
