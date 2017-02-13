#ifndef ROBOTSTEST_H
#define ROBOTSTEST_H

#include "../engines/robots.h"
#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

// The fixture for testing class Robots.
class RobotsTest : public ::testing::Test {
protected:

    RobotsTest();
    virtual ~RobotsTest();
    virtual void SetUp();
    virtual void TearDown();

    Robots *robots;

};

#endif // ROBOTSTEST_H
