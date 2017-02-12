#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "../engines/robots.h"
#include "../engines/worms.h"

// The fixture for testing class Foo.
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
 * Worms Tests *
 ****************/

TEST_F(WormsTest, TESTINITIAL) {
    EXPECT_EQ(3, worms.score()) << "Score should be 3"; //SCORE
    EXPECT_EQ('o', worms.get(1, 1)) << "Tail should be here"; //TAIL
    EXPECT_EQ('o', worms.get(2, 1)) << "Middle should be here"; //MIDDLE
    EXPECT_EQ('@', worms.get(3, 1)) << "Head should be here"; //HEAD
}

TEST_F(WormsTest, TESTDOWN) {
    worms.set(3, 2, 'x');
    worms.pressDown();
    EXPECT_EQ(3, worms.score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms.get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms.get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms.get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms.get(3, 2)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTRIGHT) {
    worms.set(4, 1, 'x');
    worms.pressRight();
    EXPECT_EQ(3, worms.score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms.get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms.get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms.get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms.get(4, 1)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTUP) {
    worms.set(3, 0, 'x');
    worms.pressUp();
    EXPECT_EQ(3, worms.score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms.get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms.get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms.get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms.get(3, 0)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTLEFT) {
    worms.pressLeft();
    EXPECT_EQ(3, worms.score()) << "Score should be 3"; //SCOREd
    EXPECT_EQ(true, worms.isLost()) << "Game should be lost";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
