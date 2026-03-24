#include <iostream>
#include "MyString.h"

MyString::MyString() : MyString(80) {
}

MyString::MyString(int size) {
    this->size = size;
    data = new char[size + 1];
    data[0] = '\0';
}

MyString::MyString(const char* str) {
    this->size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

MyString::MyString(const MyString& other) {
    this->size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

MyString::MyString(MyString&& other) noexcept {
    data = other.data;
    size = other.size;
    
    other.data = nullptr;
    other.size = 0;
}

MyString::~MyString() {
    delete[] data;
}

char MyString::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return '\0';
}

int MyString::operator()(char ch) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == ch) {
            return i;
        }
    }
    return -1;
}

MyString::operator int() const {
    return size;
}

void MyString::input() {
    cout << "Enter string: ";
    cin.getline(data, size + 1);
    this->size = strlen(data);
}

void MyString::output() const {
    cout << data;
}

int MyString::getSize() const {
    return size;
}

const char* MyString::getData() const {
    return data;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        this->size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}
