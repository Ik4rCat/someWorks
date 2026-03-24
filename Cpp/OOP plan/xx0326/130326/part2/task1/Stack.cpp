#include <iostream>
#include "Stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack() {
    top = nullptr;
    size = 0;
    capacity = 10;
}

template <typename T>
Stack<T>::Stack(int initialCapacity) {
    top = nullptr;
    size = 0;
    capacity = initialCapacity > 0 ? initialCapacity : 10;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    top = nullptr;
    size = 0;
    capacity = other.capacity;
    
    if (other.top != nullptr) {
        Node* current = other.top;
        Node* prev = nullptr;
        
        while (current != nullptr) {
            Node* newNode = new Node(current->data);
            if (top == nullptr) {
                top = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            current = current->next;
            size++;
        }
    }
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(T value) {
    if (size >= capacity) {
        capacity *= 2;
    }
    
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}

template <typename T>
void Stack<T>::pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    Node* temp = top;
    top = top->next;
    delete temp;
    size--;
}

template <typename T>
T Stack<T>::peek() const {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return T();
    }
    return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int Stack<T>::getSize() const {
    return size;
}

template <typename T>
void Stack<T>::clear() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        clear();
        capacity = other.capacity;
        
        if (other.top != nullptr) {
            Node* current = other.top;
            Node* prev = nullptr;
            
            while (current != nullptr) {
                Node* newNode = new Node(current->data);
                if (top == nullptr) {
                    top = newNode;
                } else {
                    prev->next = newNode;
                }
                prev = newNode;
                current = current->next;
                size++;
            }
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::display() const {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << "Stack (top to bottom): ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<string>;
