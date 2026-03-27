#pragma once

#include <iostream>
#include <type_traits>

class Point;

template <typename T>
class Vector {
private:
    T* data;
    size_t size_;

public:
    Vector();
    explicit Vector(size_t n);
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;

    bool empty() const;
    void resize(size_t newSize);
    void push(const T& value);
    void pop();
    void insert(size_t index, const T& value);

    void print() const;
};

template <typename Elem, typename I, typename D, typename L>
void calculateAndPrint(Vector<Elem>& vec, I i, D d, L l);

#include "Vector.inl"
