#include <iostream>
#include "MyString.h"

int MyString::objectCount = 0;

MyString::MyString() : MyString(80) {}

MyString::MyString(int size) {
    this->size = size;
    data = new char[size + 1];
    data[0] = '\0';
    objectCount++;
}

MyString::MyString(const char* str) {
    this->size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
    objectCount++;
}

MyString::MyString(const MyString& other) {
    this->size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
    objectCount++;
}

MyString::~MyString() {
    delete[] data;
    objectCount--;
}

void MyString::input() {
    cout << "Enter string: ";
    cin.getline(data, size + 1);
    this->size = strlen(data);
}

void MyString::output() const {
    cout << data;
}

int MyString::getObjectCount() {
    return objectCount;
}

int MyString::getSize() const {
    return size;
}

const char* MyString::getData() const {
    return data;
}
