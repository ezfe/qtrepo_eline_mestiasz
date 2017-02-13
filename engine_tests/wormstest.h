#ifndef WORMSTEST_H
#define WORMSTEST_H

#include "../engines/worms.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>

class WormsTest : public ::testing::Test {
protected:
    WormsTest();

    virtual ~WormsTest();
    virtual void SetUp();
    virtual void TearDown();

    Worms *worms;
};

#endif // WORMSTEST_H
