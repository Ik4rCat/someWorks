#pragma once

#include <iostream>

class Point;

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector();
    explicit Vector(size_t n);
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;

    size_t getCapacity() const;
    bool empty() const;
    void resize(size_t newSize);
    void push(const T& value);
    void pop();
    void insert(size_t index, const T& value);

    void print() const;
};

template <typename T>
void calculateAndPrint(Vector<T>& vec, int i, double d, long l);

#include "Vector.inl"
