#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node* top;
    int size;
    int capacity;

public:
    Stack();
    Stack(int initialCapacity);
    Stack(const Stack<T>& other);
    ~Stack();
    
    void push(T value);
    void pop();
    T peek() const;
    bool isEmpty() const;
    int getSize() const;
    void clear();
    
    Stack<T>& operator=(const Stack<T>& other);
    void display() const;
};
