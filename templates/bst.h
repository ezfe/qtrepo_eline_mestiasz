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

/*!
 * \brief Add new node to binary tree
 * \param T value - value for new node
 * \return bool - true if susccessfully added new node
 */
template <class T>
bool Node<T>::add_node(T value){
    if (value == this->value) return false;
    // add node at the correct branch
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

/*!
 * \brief set value for node
 * \param T value
 */
template <class T>
void Node<T>::set_value(T value){
    this->value = value;
}

/*!
 * \brief set left node
 * \param Node* node
 */
template <class T>
void Node<T>::set_left_node(Node* node){
    left = node;
}

/*!
 * \brief set right node
 * \param Node* node
 */
template <class T>
void Node<T>::set_right_node(Node* node){
    right = node;
}

/*!
 * \brief set parent for node
 * \param Node* node
 */
template <class T>
void Node<T>::set_parent(Node* node){
    parent = node;
}

/*!
 * \brief Traverse from this node (In-order)
 * \param std::stringstream& str - container for
 * keeping the string representation
 */
template <class T>
void Node<T>::traverse(std::stringstream& str){
    if (left != nullptr) left->traverse(str);
    std::cout << " " << value << " ";
    str << " " << value << " ";
    if (right != nullptr) right->traverse(str);
}

/*!
 * \brief get the node's value
 * \return T value
 */
template <class T>
T Node<T>::get_value(){
    return value;
}

/*!
 * \brief get the left child
 * \param Node* node
 */
template <class T>
Node<T>* Node<T>::get_left_node(){
    return left;
}

/*!
 * \brief get the right child
 * \param Node* node
 */
template <class T>
Node<T>* Node<T>::get_right_node(){
    return right;
}

/*!
 * \brief get the parent node
 * \param Node* node
 */
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

/*!
 * \brief Create and add new node
 * \param T value
 */
template <class T>
void BST<T>::add_node(T value){
    if (head == nullptr) {
        head = new Node<T>(value, nullptr);
        size++;
    } else {
        if (head->add_node(value)) size++;
    }
}

/*!
 * \brief find min value for the node
 * \param Node* node
 * \return Node* node
 */
template <class T>
Node<T>* BST<T>::find_min(Node<T>* node){
    if(node != nullptr)
        while(node->get_left_node() != nullptr)
            node = node->get_left_node();
    return node;
}

/*!
 * \brief remove min node (helper for remove() method)
 * \param Node* node
 * \return Node* node
 */
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

/*!
 * \brief remove node
 * \param Node* node
 * \param T value
 * \return Node* node
 */
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
/*!
 * \brief Wrapper for remove(), providing base case
 * \param T value
 * \return Node* node
 */
template <class T>
Node<T>* BST<T>::remove_node(T value){
    if(find(value) == nullptr) return head;
    size--;
    return remove(value, head);
}

/*!
 * \brief find the value
 * \param T value
 * \return Node* node
 */
template <class T>
Node<T>* BST<T>::find(T value){
    Node<T>* current = head;
    // binary search
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

/*!
 * \brief Find if tree does not have any nodes
 * \return bool
 */
template <class T>
bool BST<T>::is_empty(){
    return head == nullptr;
}

/*!
 * \brief find size of the tree
 * \return int
 */
template <class T>
int BST<T>::get_size(){
    return size;
}

/*!
 * \brief get the head
 * \return Node* node
 */
template <class T>
Node<T>* BST<T>::get_head(){
    return head;
}

/*!
 * \brief traverse through the tree(In-order)
 * \param std::string - string representation of traversal
 */
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
