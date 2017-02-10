#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "../engines/robots.h"

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


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
