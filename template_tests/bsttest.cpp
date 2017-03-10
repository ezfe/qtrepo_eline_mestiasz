#include "bsttest.h"

BSTTest::BSTTest() {
    bst = new BST<int>();
}

BSTTest::~BSTTest() {

}

void BSTTest::SetUp() {

}

void BSTTest::TearDown() {

}

TEST_F(BSTTest, TEST_REMOVAL) {
    bst->add_node(4);
    bst->add_node(2);
    bst->add_node(6);
    bst->add_node(1);
    bst->add_node(3);
    bst->add_node(5);
    bst->add_node(8);
    bst->add_node(7);
    bst->add_node(9);

    bst->traverse();
    std::cout << "Size: " << bst->get_size() << std::endl;

    bst->traverse();
    std::cout << "Size: " << bst->get_size() << std::endl;

}
