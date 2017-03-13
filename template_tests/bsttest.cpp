#include "bsttest.h"

BSTTest::BSTTest() {
}

BSTTest::~BSTTest() {

}

void BSTTest::SetUp() {
    bst = new BST<int>();
}

void BSTTest::TearDown() {
    delete bst;
}

TEST_F(BSTTest, TEST_ADD_NODE) {
    EXPECT_TRUE(bst->is_empty()) << "Could not initialize correctly";
    bst->add_node(12);
    bst->add_node(13);
    EXPECT_EQ(" 12  13 ", bst->traverse()) << "Could not add correctly";
    bst->add_node(10);
    EXPECT_EQ(" 10  12  13 ", bst->traverse()) << "Could not add correctly";
    bst->add_node(11);
    EXPECT_EQ(" 10  11  12  13 ", bst->traverse()) << "Could not add correctly";

}

TEST_F(BSTTest, TEST_FIND){
    EXPECT_TRUE(bst->is_empty()) << "Could not initialize correctly";
    bst->add_node(12);
    bst->add_node(13);
    EXPECT_EQ(13, bst->find(13)->get_value()) << "Could not find correctly";
    EXPECT_EQ(nullptr, bst->find(14)) << "Could not find correctly";

}

TEST_F(BSTTest, TEST_IS_EMPTY){
    EXPECT_TRUE(bst->is_empty()) << "Could not initialize correctly";
    bst->add_node(12);
    EXPECT_FALSE(bst->is_empty()) << "Could not find correct value";
}

TEST_F(BSTTest, TEST_GET_SIZE){
    EXPECT_EQ(0, bst->get_size()) << "Could not initialize correctly";
    bst->add_node(13);
    EXPECT_EQ(1, bst->get_size()) << "Could not find size correctly";
    bst->add_node(12);
    EXPECT_EQ(2, bst->get_size()) << "Could not find size correctly";
    bst->remove_node(12);
    EXPECT_EQ(1, bst->get_size()) << "Could not find size correctly";
}

TEST_F(BSTTest, TEST_REMOVAL) {
    bst->remove_node(6);
    EXPECT_EQ("", bst->traverse()) << "Could not remove correctly";

    bst->add_node(4);
    bst->add_node(2);
    bst->add_node(6);
    bst->add_node(1);
    bst->add_node(3);
    bst->add_node(5);
    bst->add_node(8);
    bst->add_node(7);
    bst->add_node(9);

    bst->remove_node(6);

    EXPECT_EQ(" 1  2  3  4  5  7  8  9 ", bst->traverse()) << "Could not remove correctly";
}

TEST_F(BSTTest, TEST_TRAVERSAL){
    bst->add_node(4);
    bst->add_node(2);
    bst->add_node(6);
    bst->add_node(1);
    bst->add_node(3);
    bst->add_node(5);
    bst->add_node(8);
    bst->add_node(7);
    bst->add_node(9);

    EXPECT_EQ(" 1  2  3  4  5  6  7  8  9 ", bst->traverse()) << "Could not traverse correctly";
    bst->remove_node(2);
    EXPECT_EQ(" 1  3  4  5  6  7  8  9 ", bst->traverse()) << "Could not traverse correctly";
}

TEST_F(BSTTest, TEST_FIND_MIN){
    bst->add_node(4);
    bst->add_node(2);
    bst->add_node(6);
    bst->add_node(1);
    bst->add_node(3);
    bst->add_node(5);
    bst->add_node(8);
    bst->add_node(7);
    bst->add_node(9);

    EXPECT_EQ(1, bst->find_min(bst->get_head())->get_value()) << "Could not find correct min";
    bst->remove_node(1);
    EXPECT_EQ(2, bst->find_min(bst->get_head())->get_value()) << "Could not find correct min";
    bst->remove_node(2);
    EXPECT_EQ(3, bst->find_min(bst->get_head())->get_value()) << "Could not find correct min";

}
