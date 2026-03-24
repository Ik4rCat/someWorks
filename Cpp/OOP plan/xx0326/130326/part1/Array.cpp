#include <iostream>
#include "Array.h"

using namespace std;

template <typename T>
Array<T>::Array() {
    data = nullptr;
    size = 0;
    count = 0;
    grow = 1;
}

template <typename T>
Array<T>::Array(int size, int grow) {
    this->size = size;
    this->grow = grow;
    this->count = 0;
    if (size > 0) {
        data = new T[size];
    } else {
        data = nullptr;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
    this->size = other.size;
    this->count = other.count;
    this->grow = other.grow;
    if (other.data != nullptr && size > 0) {
        data = new T[size];
        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize, int newGrow) {
    if (newGrow > 0) {
        grow = newGrow;
    }
    
    if (newSize == size) {
        return;
    }
    
    T* newData = nullptr;
    if (newSize > 0) {
        newData = new T[newSize];
        int copyCount = (newSize < count) ? newSize : count;
        for (int i = 0; i < copyCount; i++) {
            newData[i] = data[i];
        }
    }
    
    delete[] data;
    data = newData;
    size = newSize;
    
    if (count > size) {
        count = size;
    }
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return count - 1;
}

template <typename T>
bool Array<T>::IsEmpty() const {
    return count == 0;
}

template <typename T>
void Array<T>::FreeExtra() {
    if (count < size) {
        SetSize(count, grow);
    }
}

template <typename T>
void Array<T>::RemoveAll() {
    count = 0;
}

template <typename T>
T Array<T>::GetAt(int index) const {
    if (index >= 0 && index < count) {
        return data[index];
    }
    return T();
}

template <typename T>
void Array<T>::SetAt(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
        if (index >= count) {
            count = index + 1;
        }
    }
}

template <typename T>
T& Array<T>::operator[](int index) {
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    return data[index];
}

template <typename T>
int Array<T>::Add(T element) {
    if (count >= size) {
        int newSize = size + grow;
        SetSize(newSize, grow);
    }
    data[count] = element;
    count++;
    return count - 1;
}

template <typename T>
void Array<T>::Append(const Array<T>& other) {
    for (int i = 0; i < other.count; i++) {
        Add(other.data[i]);
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        count = other.count;
        grow = other.grow;
        if (other.data != nullptr && size > 0) {
            data = new T[size];
            for (int i = 0; i < count; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

template <typename T>
T* Array<T>::GetData() {
    return data;
}

template <typename T>
const T* Array<T>::GetData() const {
    return data;
}

template <typename T>
void Array<T>::InsertAt(int index, T element) {
    if (index < 0 || index > count) {
        return;
    }
    
    if (count >= size) {
        int newSize = size + grow;
        SetSize(newSize, grow);
    }
    
    for (int i = count; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    count++;
}

template <typename T>
void Array<T>::RemoveAt(int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
    }
}

template <typename T>
void Array<T>::RemoveAt(int index, int countToRemove) {
    if (index < 0 || index >= count || countToRemove <= 0) {
        return;
    }
    
    if (index + countToRemove > count) {
        countToRemove = count - index;
    }
    
    for (int i = index; i < count - countToRemove; i++) {
        data[i] = data[i + countToRemove];
    }
    count -= countToRemove;
}

template <typename T>
int Array<T>::GetCount() const {
    return count;
}

template <typename T>
void Array<T>::display() const {
    cout << "[";
    for (int i = 0; i < count; i++) {
        cout << data[i];
        if (i < count - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template class Array<int>;
template class Array<double>;
template class Array<char>;
template class Array<string>;
