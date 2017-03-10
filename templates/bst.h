#ifndef BST_H
#define BST_H

#include <iostream>
template <class T>
class Node {
public:
    Node(T value, Node* parent);
    ~Node();

    bool add_node(T value);
    T get_value();
    Node* get_left_node();
    Node* get_right_node();
    Node* get_parent();

    void set_left_node(Node* node);
    void set_right_node(Node* node);
    void set_parent(Node* node);
    void traverse();

private:
    T value;
    Node* left;
    Node* right;
    Node* parent;

};

template <class T>
Node<T>::Node(T value, Node* parent){
    this->value = value;
    this->parent = parent;
    left = nullptr;
    right = nullptr;
}

template <class T>
Node<T>::~Node(){
    if(left != nullptr) delete left;
    if(right != nullptr) delete right;
}

template <class T>
bool Node<T>::add_node(T value){
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
void Node<T>::set_left_node(Node* node){
    left = node;
}

template <class T>
void Node<T>::set_right_node(Node* node){
    right = node;
}

template <class T>
void Node<T>::set_parent(Node* node){
    parent = node;
}

template <class T>
void Node<T>::traverse(){
    if (left != nullptr) left->traverse();
    std::cout << " " << value << " ";
    if (right != nullptr) right->traverse();
}

template <class T>
T Node<T>::get_value(){
    return value;
}

template <class T>
Node<T>* Node<T>::get_left_node(){
    return left;
}

template <class T>
Node<T>* Node<T>::get_right_node(){
    return right;
}

template <class T>
Node<T>* Node<T>::get_parent(){
    return parent;
}

// BST

template <class T>
class BST {
public:
    BST();
    ~BST();
    Node<T>* find(T value);
    bool remove_node(T value);
    bool is_empty();
    int get_size();

    void add_node(T value);
    void remove_from_parent(Node<T>* node, Node<T>* current);
    void traverse();

private:
    Node<T>* head;
    int size;

};

template <class T>
BST<T>::BST(){
    head = nullptr;
    size = 0;
}

template <class T>
BST<T>::~BST(){
    if(head != nullptr) delete head;
}

template <class T>
void BST<T>::add_node(T value){
    if (head == nullptr) {
        head = new Node<T>(value, nullptr);
        size++;
    } else {
        if (head->add_node(value)) size++;
    }
}

template <class T>
bool BST<T>::remove_node(T value){
    Node<T>* node = find(value);

    if(node == nullptr) return true;

    if(node->get_right_node() == nullptr){
        remove_from_parent(node, node->get_left_node());
        return true;
    }

    Node<T>* current = node->get_right_node();
    while(current->get_left_node() != nullptr){
        current = current->get_left_node();
    }

    remove_from_parent(node, current);
    return true;
}

template <class T>
void BST<T>::remove_from_parent(Node<T>* node, Node<T>* current){
    if(node->get_parent() == nullptr){
        head = current;
    } else {
        if(node->get_parent()->get_value() > node->get_value()){
            node->get_parent()->set_left_node(current);
        } else {
            node->get_parent()->set_right_node(current);
        }
    }

    if(current != nullptr){
        if(current != head)
            current->get_parent()->set_left_node(current->get_right_node());
        current->set_parent(node->get_parent());
        if(node->get_right_node() != current)
            current->set_right_node(node->get_right_node());
        current->set_left_node(node->get_left_node());
    }
    node->set_left_node(nullptr);
    node->set_right_node(nullptr);
    size--;
    delete node;
}

template <class T>
Node<T>* BST<T>::find(T value){
    Node<T>* current = head;
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
bool BST<T>::is_empty(){
    return head == nullptr;
}

template <class T>
int BST<T>::get_size(){
    return size;
}

template <class T>
void BST<T>::traverse(){
    if(head == nullptr){
        std::cout << "There are no elements" << std::endl;
    }else{
        head->traverse();
        std::cout << std::endl;
    }

}



#endif // BST_H
