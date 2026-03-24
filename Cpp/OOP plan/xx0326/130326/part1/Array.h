#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int count;
    int grow;

public:
    Array();
    Array(int size, int grow = 1);
    Array(const Array<T>& other);
    ~Array();
    
    int GetSize() const;
    void SetSize(int size, int grow = 1);
    int GetUpperBound() const;
    bool IsEmpty() const;
    
    void FreeExtra();
    void RemoveAll();
    
    T GetAt(int index) const;
    void SetAt(int index, T value);
    
    T& operator[](int index);
    const T& operator[](int index) const;
    
    int Add(T element);
    void Append(const Array<T>& other);
    
    Array<T>& operator=(const Array<T>& other);
    
    T* GetData();
    const T* GetData() const;
    
    void InsertAt(int index, T element);
    void RemoveAt(int index);
    void RemoveAt(int index, int count);
    
    int GetCount() const;
    void display() const;
};
