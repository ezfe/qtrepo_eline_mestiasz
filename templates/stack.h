#ifndef STACK_H
#define STACK_H

/*************
 * StackItem *
 *************/

#include <iostream>

template <class T>
class StackItem {
public:
    StackItem();
    StackItem(T val);

    void set_next(StackItem* ptr) { this->next = ptr; }
    StackItem* get_next() { return this->next; }

    T get_value() { return this->value; }
private:
    T value;
    StackItem<T>* next = nullptr;
};

template <class T>
StackItem<T>::StackItem() {
    std::cerr << "No value stored, empty slot in stack present." << std::endl;
}

template <class T>
StackItem<T>::StackItem(T val) {
    this->value = val;
}

/*************
 *   Stack   *
 *************/

template <class T>
class Stack {
public:
    ~Stack();

    T pop();
    void push(T val);

    T top();

    bool is_empty() { return head == nullptr; }
    int size();
private:
    StackItem<T>* head = nullptr;
};

template <class T>
Stack<T>::~Stack() {
    StackItem<T>* curr = head;

    while(curr != nullptr) {
        StackItem<T>* temp = curr;
        curr = curr->get_next();
        delete temp;
    }
}

template <class T>
T Stack<T>::pop() {
    if (head != nullptr) {
        StackItem<T>* return_item = head;
        head = head->get_next();
        T val = return_item->get_value();
        delete return_item;
        return val;
    } else {
        std::cerr << "No elements" << std::endl;
        return 0;
    }
}

template <class T>
void Stack<T>::push(T val) {
    StackItem<T>* item = new StackItem<T>(val);
    item->set_next(this->head);
    this->head = item;
}

template <class T>
T Stack<T>::top() {
    if (head != nullptr) {
        return head->get_value();
    } else {
        std::cerr << "No elements" << std::endl;
        return 0;
    }
}

template <class T>
int Stack<T>::size() {
    StackItem<T>* curr = head;
    int size = 0;
    while(curr != nullptr) {
        size++;
        curr = curr->get_next();
    }
    return size;
}

#endif // STACK_H
