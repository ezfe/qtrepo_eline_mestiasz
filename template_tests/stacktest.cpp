#include "stacktest.h"


StackTest::StackTest() {
    intStack = new Stack<int>();
}

StackTest::~StackTest() {

}

void StackTest::SetUp() {

}

void StackTest::TearDown() {

}


/****************
 * Worms Tests *
 ****************/

TEST_F(StackTest, TESTINITIAL) {
    EXPECT_TRUE(intStack->is_empty()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->size()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->top()) << "Top element should be 0";
    EXPECT_EQ(0, intStack->pop()) << "Top element should be 0";
}

TEST_F(StackTest, TESTSINGLE) {
    intStack->push(392);
    EXPECT_FALSE(intStack->is_empty()) << "Stack shouldn't be empty";
    EXPECT_EQ(1, intStack->size()) << "Stack should have 1 element";
    EXPECT_EQ(392, intStack->top()) << "Element should be 392";
    EXPECT_EQ(392, intStack->pop()) << "Element should be 392";

    // Should be empty, copied from TESTINITIAL

    EXPECT_TRUE(intStack->is_empty()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->size()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->top()) << "Top element should be 0";
    EXPECT_EQ(0, intStack->pop()) << "Top element should be 0";
}

TEST_F(StackTest, TESTMORE) {
    intStack->push(392);
    EXPECT_FALSE(intStack->is_empty()) << "Stack shouldn't be empty";
    EXPECT_EQ(1, intStack->size()) << "Stack should have 1 element";
    EXPECT_EQ(392, intStack->top()) << "Element should be 392";

    intStack->push(239);
    EXPECT_FALSE(intStack->is_empty()) << "Stack shouldn't be empty";
    EXPECT_EQ(2, intStack->size()) << "Stack should have 2 element";
    EXPECT_EQ(239, intStack->top()) << "Element should be 239";

    intStack->push(932);
    EXPECT_FALSE(intStack->is_empty()) << "Stack shouldn't be empty";
    EXPECT_EQ(3, intStack->size()) << "Stack should have 3 element";
    EXPECT_EQ(932, intStack->top()) << "Element should be 932";

    EXPECT_EQ(intStack->top(), intStack->pop());
    EXPECT_EQ(intStack->top(), intStack->pop());
    EXPECT_EQ(intStack->top(), intStack->pop());

    // Should be empty, copied from TESTINITIAL

    EXPECT_TRUE(intStack->is_empty()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->size()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->top()) << "Top element should be 0";
    EXPECT_EQ(0, intStack->pop()) << "Top element should be 0";

    intStack->push(1);
    EXPECT_FALSE(intStack->is_empty()) << "Stack shouldn't be empty";
    EXPECT_EQ(1, intStack->size()) << "Stack should have 3 element";
    EXPECT_EQ(1, intStack->top()) << "Element should be 932";

    EXPECT_EQ(intStack->top(), intStack->pop());

    // Should be empty, copied from TESTINITIAL

    EXPECT_TRUE(intStack->is_empty()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->size()) << "Stack should be empty";
    EXPECT_EQ(0, intStack->top()) << "Top element should be 0";
    EXPECT_EQ(0, intStack->pop()) << "Top element should be 0";
}
