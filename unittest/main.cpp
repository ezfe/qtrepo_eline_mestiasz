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
    l1.flush();
    l1.close();

    Config s1;
    Config s2("./random.txt");
    s2.set_value("Foo", "Bar");
    s2.save_state();
    s2.print_state();
    ASSERT_EQ(s1.get_filename(), s2.get_filename()) << s1.get_filename() << " and " << s2.get_filename() << " should match!";
}


TEST_F(FooTest, TESTFIXTURE) {

    ASSERT_EQ(s1.get_filename(), s2.get_filename()) << "These should match!";
}

TEST_F(FooTest, TEST_FILE_NAMES) {
    Config c1("./foo/bar/random.txt");
    Config c2;
    c2.set_file_name("random.txt");
    c2.set_path("./foo/bar/");
    EXPECT_EQ(c1.get_filename(), c2.get_filename());
    EXPECT_EQ(c1.get_filepath(), c2.get_filepath());
}

TEST_F(FooTest, TEST_GENERATE_MAP) {
    Config c1("./foo/bar/random.txt");
    c1.generate_map();
    EXPECT_EQ("applevalue", c1.get_value("apple"));
    EXPECT_EQ("microsoftvalue", c1.get_value("microsoft"));
    EXPECT_EQ("sonyvalue", c1.get_value("sony"));
}

TEST_F(FooTest, TEST_CLEAR_STATE) {
    Config c1("./foo/bar/random.txt");
    c1.generate_map();
    c1.clear_state();
    EXPECT_EQ("", c1.get_value("apple"));
    EXPECT_EQ("", c1.get_value("microsoft"));
    EXPECT_EQ("", c1.get_value("sony"));
}

TEST_F(FooTest, TEST_LOG_INIT) {
    Log l1("./filename_special.txt", false);
    EXPECT_EQ("./filename_special.txt", l1.get_filepath());
}

TEST_F(FooTest, TEST_LOG_OPEN) {
    Log l1("./filename_special.txt", true);
    EXPECT_EQ(l1.is_open(), true);
}

TEST_F(FooTest, TEST_LOG_CLOSE) {
    Log l1("./filename_special.txt", true);
    l1.close();
    EXPECT_EQ(l1.is_open(), false);
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
