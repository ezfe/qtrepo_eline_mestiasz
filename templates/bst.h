#ifndef BST_H
#define BST_H

#include <iostream>

template <class T>
class BST {
public:
    BST();
    ~BST();
    void add_node(T value);
    Node* find(T value);
    bool remove_node(T value);
    bool is_empty();
    int get_size();

    void traverse();

private:
    Node* head;
    int size;

};

template <class T>
BST::BST(){
    head = nullptr;
    size = 0;
}

template <class T>
BST::~BST(){
    if(head != nullptr) delete head;
}

template <class T>
void BST::add_node(T value){
    if (head == nullptr) {
        head = new Node(value, nullptr);
        size++;
    } else {
        if (head->add_child(value)) size++;
    }
}

template <class T>
bool BST::remove_node(T value){
    Node* node = find(value);

    if(node == nullptr) return true;

    if(node->get_right_node() == nullptr){
        if(node->parent->get_left_node() == node)
            node->parent->set_left_node(nullptr);
        else
            node->parent->set_right_node(nullptr);
    }
}

template <class T>
Node* BST::find_node(T value){
    Node* current = head;
    while(current != nullptr){
        if(value == current->get_value())
            return current;

        if(value > current->get_value())
            current = current->get_right_node();
        else if(value < current->get_value())
            current = current->get_left_node();
    }

    return nullptr;
}

template <class T>
bool BST::is_empty(){
    return head == nullptr;
}

template <class T>
int BST::get_size(){
    return size;
}

template <class T>
void BST::traverse(){
    head->traverse();
}

template <class T>
class Node {
public:
    Node(T value);
    ~Node();

    bool add_node(T value);
    T get_value();
    Node* get_left_node();
    Node* get_right_node();

    void traverse();

private:
    T value;
    Node* left;
    Node* right;
    Node* parent;

};

template <class T>
Node::Node(T value, Node* parent){
    this->value = value;
    this->parent = parent;
    left = nullptr;
    right = nullptr;
}

template <class T>
Node::~Node(){
    if(left != nullptr) delete left;
    if(right != nullptr) delete right;
}

template <class T>
bool Node::add_node(T value){
    if (value == this->value) return false;

    if (value > this->value) {
        if(right == nullptr)
            right = new Node(value, this);
        else
            return right->add_node(value);
    } else {
        if(left == nullptr)
            left = new Node(value, this);
        else
            return left->add_node(value);
    }

    return true;
}

template <class T>
void Node::traverse(){
    if (left != nullptr) left->traverse();
    std::cout << " " << value << " ";
    if (right != nullptr) right->traverse();
}


template <class T>
Node* Node::get_left_node(){
    return left;
}

template <class T>
Node* Node::get_right_node(){
    return right;
}

#endif // BST_H
