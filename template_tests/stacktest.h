#ifndef STACKTEST_H
#define STACKTEST_H

#include "../templates/stack.h"
#include "gtest/gtest.h"

class StackTest: public ::testing::Test {
protected:
    StackTest();

    virtual ~StackTest();
    virtual void SetUp();
    virtual void TearDown();

    Stack<int>* intStack;
};

#endif // STACKTEST_H
