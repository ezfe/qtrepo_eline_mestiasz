#include <iostream>

#include "stack.h"
#include "bst.h"

using namespace std;

int main(int argc, char *argv[])
{
    Stack<int>* test = new Stack<int>();

    test->push(96);
    test->push(43);
    test->push(3);
    std::cout << test->pop() << std::endl;
    std::cout << test->pop() << std::endl;
    test->push(103);
    test->push(23);
    test->push(9);
    std::cout << test->pop() << std::endl;
    std::cout << test->pop() << std::endl;

    delete test;

    BST<int>* bst = new BST<int>();
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

    delete bst;

    return 0;
}
