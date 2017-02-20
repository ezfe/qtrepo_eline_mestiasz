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
    EXPECT_EQ('o', worms->get_xy(1, 1)) << "Tail should be here"; //TAIL
    EXPECT_EQ('o', worms->get_xy(2, 1)) << "Middle should be here"; //MIDDLE
    EXPECT_EQ('@', worms->get_xy(3, 1)) << "Head should be here"; //HEAD
}

TEST_F(WormsTest, TESTDOWN) {
    worms->set_xy(3, 2, 'x');
    worms->press_down();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get_xy(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get_xy(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get_xy(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get_xy(3, 2)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTRIGHT) {
    worms->set_xy(4, 1, 'x');
    worms->press_right();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get_xy(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get_xy(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get_xy(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get_xy(4, 1)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTUP) {
    worms->set_xy(3, 0, 'x');
    worms->press_up();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    EXPECT_FALSE('o' == worms->get_xy(1, 1)) << "Tail should no longer be here"; //OLD TAIL
    EXPECT_EQ('o', worms->get_xy(2, 1)) << "Tail should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get_xy(3, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get_xy(3, 0)) << "Head should be here"; //NEW HEAD
}

TEST_F(WormsTest, TESTLEFT) {
    worms->press_left();
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCOREd
    EXPECT_EQ(true, worms->is_lost()) << "Game should be lost";
}

TEST_F(WormsTest, TESTEGG) {
    EXPECT_EQ(3, worms->score()) << "Score should be 3"; //SCORE
    worms->set_xy(4, 1, '2');
    worms->press_right();
    EXPECT_EQ(5, worms->score()) << "Score should be 5"; //SCORE
    worms->set_xy(4, 2, 'x');
    worms->press_down();
    worms->set_xy(3, 2, 'x');
    worms->press_left();

    EXPECT_EQ('o', worms->get_xy(2, 1)) << "Tail should not move"; //NEW TAIL
    EXPECT_EQ('o', worms->get_xy(3, 1)) << "Middle should be here"; //NEW TAIL
    EXPECT_EQ('o', worms->get_xy(4, 1)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('o', worms->get_xy(4, 2)) << "Middle should be here"; //NEW MIDDLE
    EXPECT_EQ('@', worms->get_xy(3, 2)) << "Head should be here"; //NEW MIDDLE

    EXPECT_EQ(5, worms->score()) << "Score should be 5 (still)"; //SCORE
}

TEST_F(WormsTest, TESTget_head) {
    std::vector<int> head = worms->get_head();
    EXPECT_EQ(worms->get_xy(head[0], head[1]), '@') << "get_head should return the tile with @";
}

TEST_F(WormsTest, TESTget_tail) {
    std::vector<int> head = worms->get_tail();
    EXPECT_EQ(worms->get_xy(head[0], head[1]), 'o') << "get_tail should return a tile with o";
}

TEST_F(WormsTest, TEST_queued_interuption){
    worms->set_xy(5, 1, '9');
    worms->controller('L');
    EXPECT_EQ('@', worms->get_xy(5, 1));
}
