#include <iostream>

#include "gtest/gtest.h"
#include "../engines/robots.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:

    FooTest() {
      // You can do set-up work for each test here.
    }

    virtual ~FooTest() {
      // You can do clean-up work that doesn't throw exceptions here.
    }

    virtual void SetUp() {
        robots_01;
    }

    virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }

    Robots robots_01;

};

TEST_F(FooTest, TESTFIXTURE) {

    ASSERT_EQ("foo", "foo") << "These should match!";
}



int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
