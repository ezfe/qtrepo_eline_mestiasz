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
    bst->add_node(12);
    bst->add_node(13);
    bst->add_node(10);
    bst->add_node(1);
    bst->traverse();

    return 0;
}
