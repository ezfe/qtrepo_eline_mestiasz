#include <iostream>

#include "gtest/gtest.h"
#include "../tools/config.h"

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
      // Code here will be called immediately after the constructor (right
      // before each test).
    }

    virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }

    Config s1;
    Config s2;

};

TEST(general, TESTSIMPLE) {

  Config s1;
  Config s2("./random.txt");
  ASSERT_EQ(s1.get_filename(), s2.get_filename()) << s1.get_filename()
                                                  << " and "
                                                  << s2.get_filename()
                                                  << " should match!";
}


TEST_F(FooTest, TESTFIXTURE) {

  ASSERT_EQ(s1.get_filename(), s2.get_filename()) << "These should match!";
}


int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
