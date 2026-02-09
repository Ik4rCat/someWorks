#pragma once
#include <iostream>
#include <typeinfo>
#include <string>

template<typename T>
class Box
{
private:
    T value;  

public:
    T Get() {
        return value;
    }

    void Set(T val) {
        value = val;
    }

    void ToString() {
        cout << "In Box " << typename.name << " :: " << value << std::endl;
    }
};