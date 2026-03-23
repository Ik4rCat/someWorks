#pragma once

#include <iostream>

using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array();
    explicit Array(int size);
    Array(const Array& other);
    ~Array();
    
    void resize(int newSize);
    void fill();
    void display() const;
    void sort();
    int getMin() const;
    int getMax() const;
    int getSize() const;
    void setElement(int index, int value);
    int getElement(int index) const;
    
    Array& operator=(const Array& other);
};
