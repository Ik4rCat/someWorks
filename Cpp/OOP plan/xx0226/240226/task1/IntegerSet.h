#pragma once

#include <iostream>

using namespace std;

class IntegerSet {
private:
    int* elements;
    int size;
    int capacity;
    
    bool contains(int value) const;
    void resize();

public:
    IntegerSet();
    IntegerSet(int initialCapacity);
    IntegerSet(const IntegerSet& other);
    ~IntegerSet();
    
    int getSize() const;
    bool isEmpty() const;
    
    IntegerSet& operator+(int value);
    IntegerSet& operator+=(int value);
    IntegerSet operator+(const IntegerSet& other) const;
    IntegerSet& operator+=(const IntegerSet& other);
    
    IntegerSet& operator-(int value);
    IntegerSet& operator-=(int value);
    IntegerSet operator-(const IntegerSet& other) const;
    IntegerSet& operator-=(const IntegerSet& other);
    
    IntegerSet operator*(const IntegerSet& other) const;
    IntegerSet& operator*=(const IntegerSet& other);
    
    IntegerSet& operator=(const IntegerSet& other);
    bool operator==(const IntegerSet& other) const;
    
    friend ostream& operator<<(ostream& os, const IntegerSet& set);
    friend istream& operator>>(istream& is, IntegerSet& set);
};
