#include <iostream>

#include "gtest/gtest.h"
#include "../tools/config.h"
#include "../tools/log.h"

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
    Log l1;

};

TEST(general, TESTSIMPLE) {

    Log l1("./test.txt", true);
    l1 << "test " << " test " << " test " << " test " << 1 << " " << 0.11 << 'm';
    std::cout << l1.isOpen() << " huh " << std::endl;
    l1.flush();
    l1.close();

    Config s1;
    Config s2("./random.txt");
    s2.setValue("Foo", "Bar");
    s2.saveState();
    s2.printState();
    ASSERT_EQ(s1.get_filename(), s2.get_filename()) << s1.get_filename()
                                                  << " and "
                                                  << s2.get_filename()
                                                  << " should match!";
}


TEST_F(FooTest, TESTFIXTURE) {

    ASSERT_EQ(s1.get_filename(), s2.get_filename()) << "These should match!";
}

TEST_F(FooTest, TESTFILENAMES) {
    Config c1("./foo/bar/random.txt");
    Config c2;
    c2.setFileName("random.txt");
    c2.setPath("./foo/bar/");
    EXPECT_EQ(c1.get_filename(), c2.get_filename());
    EXPECT_EQ(c1.get_filepath(), c2.get_filepath());
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
