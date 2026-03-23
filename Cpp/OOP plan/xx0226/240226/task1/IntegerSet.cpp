#include <iostream>
#include "IntegerSet.h"

using namespace std;

IntegerSet::IntegerSet() {
    capacity = 10;
    elements = new int[capacity];
    size = 0;
}

IntegerSet::IntegerSet(int initialCapacity) {
    capacity = initialCapacity > 0 ? initialCapacity : 10;
    elements = new int[capacity];
    size = 0;
}

IntegerSet::IntegerSet(const IntegerSet& other) {
    capacity = other.capacity;
    size = other.size;
    elements = new int[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

IntegerSet::~IntegerSet() {
    delete[] elements;
}

bool IntegerSet::contains(int value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return true;
        }
    }
    return false;
}

void IntegerSet::resize() {
    int newCapacity = capacity * 2;
    int* newElements = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

int IntegerSet::getSize() const {
    return size;
}

bool IntegerSet::isEmpty() const {
    return size == 0;
}

IntegerSet& IntegerSet::operator+(int value) {
    if (!contains(value)) {
        if (size >= capacity) {
            resize();
        }
        elements[size] = value;
        size++;
    }
    return *this;
}

IntegerSet& IntegerSet::operator+=(int value) {
    return *this + value;
}

IntegerSet IntegerSet::operator+(const IntegerSet& other) const {
    IntegerSet result(*this);
    for (int i = 0; i < other.size; i++) {
        result += other.elements[i];
    }
    return result;
}

IntegerSet& IntegerSet::operator+=(const IntegerSet& other) {
    for (int i = 0; i < other.size; i++) {
        *this += other.elements[i];
    }
    return *this;
}

IntegerSet& IntegerSet::operator-(int value) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            for (int j = i; j < size - 1; j++) {
                elements[j] = elements[j + 1];
            }
            size--;
            break;
        }
    }
    return *this;
}

IntegerSet& IntegerSet::operator-=(int value) {
    return *this - value;
}

IntegerSet IntegerSet::operator-(const IntegerSet& other) const {
    IntegerSet result(*this);
    for (int i = 0; i < other.size; i++) {
        result -= other.elements[i];
    }
    return result;
}

IntegerSet& IntegerSet::operator-=(const IntegerSet& other) {
    for (int i = 0; i < other.size; i++) {
        *this -= other.elements[i];
    }
    return *this;
}

IntegerSet IntegerSet::operator*(const IntegerSet& other) const {
    IntegerSet result;
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result += elements[i];
        }
    }
    return result;
}

IntegerSet& IntegerSet::operator*=(const IntegerSet& other) {
    IntegerSet result = *this * other;
    delete[] elements;
    elements = new int[result.capacity];
    size = result.size;
    capacity = result.capacity;
    for (int i = 0; i < size; i++) {
        elements[i] = result.elements[i];
    }
    return *this;
}

IntegerSet& IntegerSet::operator=(const IntegerSet& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new int[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

bool IntegerSet::operator==(const IntegerSet& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const IntegerSet& set) {
    os << "{";
    for (int i = 0; i < set.size; i++) {
        os << set.elements[i];
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

istream& operator>>(istream& is, IntegerSet& set) {
    int count;
    cout << "Enter number of elements: ";
    is >> count;
    
    cout << "Enter elements: ";
    for (int i = 0; i < count; i++) {
        int value;
        is >> value;
        set += value;
    }
    return is;
}
