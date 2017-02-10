#include <iostream>

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

    }

    virtual void TearDown() {

    }

    Robots robots;

};

TEST_F(RobotsTest, TESTINITIALIZATION) {
    robots.redraw();

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



int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
