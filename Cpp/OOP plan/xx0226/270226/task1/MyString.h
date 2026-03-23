#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* data;
    int size;
    static int objectCount;

public:
    MyString();
    MyString(int size);
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();
    
    void input();
    void output() const;
    static int getObjectCount();
    
    int getSize() const;
    const char* getData() const;
    
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
};
