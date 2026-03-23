#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char* fullName;
    int age;

public:
    Person();
    Person(const char* fullName, int age);
    Person(const Person& other);
    ~Person();
    
    const char* getFullName() const;
    int getAge() const;
    
    void setFullName(const char* fullName);
    void setAge(int age);
    
    void display() const;
    void input();
    
    Person& operator=(const Person& other);
};
