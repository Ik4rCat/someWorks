#include <iostream>
#include "Array.h"
#include <sstream>
#include <cstring>

Array::Array() {
    size = 0;
    data = nullptr;
}

Array::Array(int size) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

Array::Array(const Array& other) {
    this->size = other.size;
    if (other.data != nullptr) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

Array::Array(Array&& other) noexcept {
    data = other.data;
    size = other.size;
    
    other.data = nullptr;
    other.size = 0;
}

Array::~Array() {
    delete[] data;
}

int& Array::operator[](int index) {
    return data[index];
}

int Array::operator[](int index) const {
    return data[index];
}

void Array::operator()(int value) {
    for (int i = 0; i < size; i++) {
        data[i] += value;
    }
}

Array::operator int() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

Array::operator char*() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < size; i++) {
        ss << data[i];
        if (i < size - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    
    string str = ss.str();
    char* result = new char[str.length() + 1];
    strcpy(result, str.c_str());
    return result;
}

void Array::resize(int newSize) {
    int* newData = new int[newSize];
    int copySize = (newSize < size) ? newSize : size;
    
    for (int i = 0; i < copySize; i++) {
        newData[i] = data[i];
    }
    
    for (int i = copySize; i < newSize; i++) {
        newData[i] = 0;
    }
    
    delete[] data;
    data = newData;
    size = newSize;
}

void Array::fill() {
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element [" << i << "]: ";
        cin >> data[i];
    }
}

void Array::display() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Array::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int Array::getMin() const {
    if (size == 0) return 0;
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

int Array::getMax() const {
    if (size == 0) return 0;
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

int Array::getSize() const {
    return size;
}

void Array::setElement(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

int Array::getElement(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        this->size = other.size;
        if (other.data != nullptr) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}
