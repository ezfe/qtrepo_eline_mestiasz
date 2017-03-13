#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>

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

    void set_value(T value);
    void set_left_node(Node* node);
    void set_right_node(Node* node);
    void set_parent(Node* node);
    void traverse(std::stringstream& str);

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
void Node<T>::set_value(T value){
    this->value = value;
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
void Node<T>::traverse(std::stringstream& str){
    if (left != nullptr) left->traverse(str);
    std::cout << " " << value << " ";
    str << " " << value << " ";
    if (right != nullptr) right->traverse(str);
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
    Node<T>* find_min(Node<T>* node);
    Node<T>* remove_min(Node<T>* node);
    Node<T>* remove(T value, Node<T>* node);
    Node<T>* remove_node(T value);
    Node<T>* get_head();
    std::string traverse();
    bool is_empty();
    int get_size();

    void add_node(T value);

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
Node<T>* BST<T>::find_min(Node<T>* node){
    if(node != nullptr)
        while(node->get_left_node() != nullptr)
            node = node->get_left_node();
    return node;
}

template <class T>
Node<T>* BST<T>::remove_min(Node<T>* node){
    if(node == nullptr){
        throw;
    } else if(node->get_left_node() != nullptr){
        node->set_left_node(remove_min(node->get_left_node()));
        return node;
    } else {
        return node->get_right_node();
    }
}


template <class T>
Node<T>* BST<T>::remove(T value, Node<T>* node){
    if(value < node->get_value())
        node->set_left_node(remove(value, node->get_left_node()));
    else if(value > node->get_value())
        node->set_right_node(remove(value, node->get_right_node()));
    else if(node->get_left_node() != nullptr && node->get_right_node() != nullptr){
        node->set_value(find_min(node->get_right_node())->get_value());
        node->set_right_node(remove_min(node->get_right_node()));
    } else {
        if(node->get_left_node() != nullptr)
            node = node->get_left_node();
        else
            node = node->get_right_node();
    }

    return node;

}

template <class T>
Node<T>* BST<T>::remove_node(T value){
    if(find(value) == nullptr) return head;
    size--;
    return remove(value, head);
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
Node<T>* BST<T>::get_head(){
    return head;
}

template <class T>
std::string BST<T>::traverse(){
    std::stringstream str;
    if(head == nullptr){
        std::cout << "There are no elements" << std::endl;
    }else{
        head->traverse(str);
        std::cout << std::endl;
    }
    return str.str();
}



#endif // BST_H
