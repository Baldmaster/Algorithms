#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <iomanip>
#include <memory>


template <typename T>
class Stack {
    struct Node {
        T data;
        struct Node* next = nullptr;
    };
private:
    struct Node* top = nullptr;
public:
    void push(T);
    bool pop();
    void show();
};

template <typename T>
void Stack<T>::push(T data) {
    struct Node* newNode = new struct Node;
    newNode -> data = data;
    if (this -> top == nullptr)
        newNode -> next = nullptr;
    else 
        newNode -> next = this -> top;

    this -> top = newNode;
}

template <typename T>
bool Stack<T>::pop() {
    if (this -> top == nullptr)
        return false;
    else {
        struct Node* temp = this -> top;
        this -> top = temp -> next;
        delete temp;
    }
    
    return true;
}

template <typename T>
void Stack<T>::show() {
    struct Node* tmp = this -> top;

    std::cout << "\n--- Stack ---\n" << std::endl;
    
    while (tmp) {
        std::cout << std::setw(4) << tmp -> data << ";"
                  << std::endl;
        tmp = tmp -> next;
    }

    std::cout << "\n--- ===== ---\n" << std::endl;
}

#endif
