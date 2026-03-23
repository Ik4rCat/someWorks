#include <iostream>
#include "Person.h"

Person::Person() {
    fullName = new char[1];
    fullName[0] = '\0';
    age = 0;
}

Person::Person(const char* fullName, int age) {
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
    this->age = age;
}

Person::Person(const Person& other) {
    this->fullName = new char[strlen(other.fullName) + 1];
    strcpy(this->fullName, other.fullName);
    this->age = other.age;
}

Person::~Person() {
    delete[] fullName;
}

const char* Person::getFullName() const {
    return fullName;
}

int Person::getAge() const {
    return age;
}

void Person::setFullName(const char* fullName) {
    delete[] this->fullName;
    this->fullName = new char[strlen(fullName) + 1];
    strcpy(this->fullName, fullName);
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::display() const {
    cout << "  Name: " << fullName << ", Age: " << age;
}

void Person::input() {
    char temp[100];
    cout << "Enter full name: ";
    cin.getline(temp, 100);
    setFullName(temp);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] fullName;
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
        age = other.age;
    }
    return *this;
}
