#pragma once

#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();
    
    void append(T value);
    void prepend(T value);
    void insertAt(int index, T value);
    void removeAt(int index);
    void removeValue(T value);
    bool contains(T value) const;
    int indexOf(T value) const;
    
    LinkedList<T>* clone() const;
    LinkedList<T>* operator+(const LinkedList<T>& other) const;
    LinkedList<T>* operator*(const LinkedList<T>& other) const;
    
    LinkedList<T>& operator=(const LinkedList<T>& other);
    
    int getSize() const;
    bool isEmpty() const;
    void clear();
    void display() const;
    
    T& operator[](int index);
    const T& operator[](int index) const;
};
