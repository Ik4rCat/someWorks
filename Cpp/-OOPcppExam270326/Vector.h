#pragma once

#include <iostream>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;

public:
    Vector();
    explicit Vector(size_t n);
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;

    void print() const;
};

template <typename T>
void calculateAndPrint(Vector<T>& vec, int i, double d, long l);

#include "Vector.inl"
