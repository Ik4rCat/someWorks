#pragma once

#include <iostream>
using namespace std;

class Person {
private:
    char* fullName;
    int age;

public:
    Person();
    Person(const char* fullName, int age);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    ~Person();
    
    const char* getFullName() const;
    int getAge() const;
    
    void setFullName(const char* fullName);
    void setAge(int age);
    
    Person& operator=(const Person& other);
    Person& operator=(Person&& other) noexcept;
    
    void display() const;
    void input();
};
