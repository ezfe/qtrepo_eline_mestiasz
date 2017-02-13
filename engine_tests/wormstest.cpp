#include "wormstest.h"


WormsTest::WormsTest() {
    worms = new Worms(10,10);
}

WormsTest::~WormsTest() {

}

void WormsTest::SetUp() {

}

void WormsTest::TearDown() {

}


/****************
 * Worms Tests *
 ****************/

TEST_F(WormsTest, TESTINITIAL) {
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_EQ('o', worms->get(1, 1)) << "Tail should be here"; //TAIL
    EXPECT_EQ('o', worms->get(2, 1)) << "Middle should be here"; //MIDDLE
    EXPECT_EQ('@', worms->get(3, 1)) << "Head should be here"; //HEAD
}

TEST_F(WormsTest, TESTDOWN) {
    worms->set(3, 2, 'x');
    worms->pressDown();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get(3, 2)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTRIGHT) {
    worms->set(4, 1, 'x');
    worms->pressRight();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get(4, 1)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTUP) {
    worms->set(3, 0, 'x');
    worms->pressUp();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get(3, 0)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTLEFT) {
    worms->pressLeft();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCOREd
    EXPECT_EQ(true, worms->isLost()) << "Game should be lost";
}

TEST_F(WormsTest, TESTEGG) {
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    worms->set(4, 1, '2');
    worms->pressRight();
    EXPECT_EQ(5, worms->score()) << "Score should be 5"; //SCORE
    worms->set(4, 2, 'x');
    worms->pressDown();
    worms->set(3, 2, 'x');
    worms->pressLeft();

    EXPECT_EQ('o', worms->get(2, 1)) << "Tail should not move"; //NEW TAIL
    EXPECT_EQ('o', worms->get(3, 1)) << "Middle should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get(4, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('o', worms->get(4, 2)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get(3, 2)) << "Head should be here"; //NEW MIDDLE

    EXPECT_EQ(5, worms->score()) << "Score should be 5 (still)"; //SCORE
}

TEST_F(WormsTest, TESTGETHEAD) {
    std::vector<int> head = worms->getHead();
    EXPECT_EQ(worms->get(head[0], head[1]), '@') << "GetHead should return the tile with @";
}

TEST_F(WormsTest, TESTGETTAIL) {
    std::vector<int> head = worms->getTail();
    EXPECT_EQ(worms->get(head[0], head[1]), 'o') << "GetTail should return a tile with o";
}

