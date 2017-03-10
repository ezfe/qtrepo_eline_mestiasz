#ifndef STACKTEST_H
#define STACKTEST_H

#include "../templates/bst.h"
#include "gtest/gtest.h"

class BSTTest: public ::testing::Test {
protected:
    BSTTest();

    virtual ~BSTTest();
    virtual void SetUp();
    virtual void TearDown();

    BST<int>* bst;
};

#endif // STACKTEST_H
