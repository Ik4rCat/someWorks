#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* data;
    int size;

public:
    MyString();
    MyString(int size);
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();
    
    char operator[](int index) const;
    int operator()(char ch) const;
    operator int() const;
    
    void input();
    void output() const;
    int getSize() const;
    const char* getData() const;
    
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
};
